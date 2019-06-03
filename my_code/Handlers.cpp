#include "Handlers.h"
#include "Data.h"
#include "User.h"
#include "Publisher.h"
#include "Film.h"
#include "Recommender.h"

using namespace std;

Response* signupHandler::callback(Request* req)
{
	Response* res;
  	request = req;
  	if (checkSignupInfo() == username)
  		res = Response::redirect("/usernameErr");
  	else if (checkSignupInfo() == pass)
  		res = Response::redirect("/passErr");
  	string sessionId = signup();
  	res = Response::redirect("/home");
  	res->setSessionId(sessionId);
  	return res;
}

signupErr signupHandler::checkSignupInfo()
{
	if (request->getBodyParam(PASSWORD) != request->getBodyParam(PASSCONFIRM))
		return pass;
	if (data->find_user(request->getBodyParam(USERNAME)) != NULL)
		return username;
	return ok;
}

string signupHandler::signup()
{
	User* new_user;
	map<string, string> userInfo;
	userInfo[USERNAME] = request->getBodyParam(USERNAME);
	userInfo[PASSWORD] = request->getBodyParam(PASSWORD);
	userInfo[AGE] = request->getBodyParam(AGE);
	userInfo[EMAIL] = request->getBodyParam(EMAIL);
	userInfo[USER_ID] = to_string(data->get_new_user_id());
	if (request->getBodyParam(PUBLISHER) == PUBLISHER)
	{
		userInfo[PUBLISHER] == _TRUE;
		new_user = new Publisher(userInfo);
	}
	else
	{
		userInfo[PUBLISHER] = _FALSE;
		new_user = new User(userInfo);
	}
	data->add_new_user(new_user);
	return userInfo[USER_ID];
}

inline signupHandler::signupHandler(Data* _data)
{
	data = _data;
}

inline loginHandler::loginHandler(Data* _data)
{
	data = _data;
}

Response* loginHandler::callback(Request* req)
{
	Response* res;
	if (!data->find_user(req->getBodyParam(USERNAME))->check_password(req->getBodyParam(PASSWORD)))
		res = Response::redirect("/loginPassErr");
  	res = Response::redirect("/home");
  	string sessionId = to_string(data->find_user(req->getBodyParam(USERNAME))->get_id());
  	res->setSessionId(sessionId);
  	return res;
}

Response* logoutHandler::callback(Request* req)
{
	if (req->getSessionId() == EMPTY_SESSION_ID)
		throw server::Exception("You have to login first!");
  	Response* res = Response::redirect("/");
  	res->setSessionId(EMPTY_SESSION_ID);
  	return res;
}

inline homeHandler::homeHandler(string filePath) : TemplateHandler(filePath), data(_data) {}

map<string, string> homeHandler::handle(Request *req) 
{
 	int userId = req->getSessionId();
 	map<string, string> context;
  	if (!data->find_user(userId)->is_publisher())
  	{
  		context = getHomeFilms(userId);
  		context[PUBLISHER] = _FALSE;
  	}
  	else
  	{
  		context = getPublishedFilms(userId);
  		context[PUBLISHER] = _TRUE;
  	}
  	return context;
}

map<string, string> homeHandler::getPublishedFilms(int userId)
{
	return changeVectorToMap((Publisher*)(data->find_user(userId))->get_published_films());
}

map<string, string> homeHandler::getHomeFilms(int userId)
{
	vector<FilmInfo> filmsInfo;
	vector<Film*> films = data->get_films();
	for (int i = 0; i <films.size(); i++)
		if ((!films[i]->is_deleted()) && (data->find_user(userId)->check_can_buy_film(films[i]->get_price())))
			filmsInfo.push_back(films[i]->set_info());
	return changeVectorToMap(filmsInfo);
}

map<string, string> homeHandler::changeVectorToMap(vector<filmInfo>)
{
	map<string, string> info;
	info[SIZE] = to_string(filmsInfo.size());
	for (int i = 0; i < filmsInfo.size(); i++)
	{
		string num = to_string(i);
		info[NAME + num] = filmsInfo[i].name;
		info[FILM_ID + num] = to_string(filmsInfo[i].id);
		info[LENGTH + num] = to_string(filmsInfo[i].length);
		info[PRICE + num] = to_string(filmsInfo[i].price);
		info[RATE + num] = to_string(filmsInfo[i].rate);
		info[YEAR + num] = to_string(filmsInfo[i].year);
		info[DIRECTOR + num] = filmsInfo[i].id;
		info[SUMMARY + num] = filmsInfo[i].id;
	}
	return info;
}

inline deleteFilmHandler::deleteFilmHandler(Data* _data)
{
	data = _data;
}

Response* deleteFilmHandler::callback(Request* req)
{
	userId = req->getSessionId(); 
	if ((userId == EMPTY_SESSION_ID) || (!data->find_user(userId)->is_publisher()))
		throw server::Exception("You have to login first!");
	((Publisher*)(data->find_user(userId)))->delete_film(stoi(req->getBodyParam(FILM_ID)));
  	Response* res = Response::redirect("/home");
  	res->setSessionId(userId);
  	return res;
}

inline addFilmHandler::addFilmHandler(Data* _data, Recommender* _recommender)
{
	data = _data;
	recommender = _recommender;
}

Response* addFilmHandler::callback(Request* req)
{
	userId = req->getSessionId(); 
	if ((userId == EMPTY_SESSION_ID) || (!data->find_user(userId)->is_publisher()))
		throw server::Exception("You have to login first!");
	addFilm(req);
  	Response* res = Response::redirect("/home");
  	res->setSessionId(userId);
  	return res;
}

void addFilmHandler::addFilm(Request* req)
{
	map<string, string> filmInfo;
	filmInfo[NAME] = request->getBodyParam(NAME);
	filmInfo[LENGTH] = request->getBodyParam(LENGTH);
	filmInfo[PRICE] = request->getBodyParam(PRICE);
	filmInfo[YEAR] = request->getBodyParam(YEAR);
	filmInfo[DIRECTOR] = request->getBodyParam(DIRECTOR);
	filmInfo[SUMMARY] = request->getBodyParam(YEAR);
	filmInfo[FILM_ID] = to_string(data->get_new_film_id());
	Film* new_film = ((Publisher*)(data->find_user(req->getSessionId())))->add_film(filmInfo);
	data->add_new_film(new_film);
	recommender->add_new_element_to_graph();
}
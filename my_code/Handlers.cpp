#include "Handlers.h"
#include "Data.h"
#include "User.h"
#include "Publisher.h"
#include "Film.h"

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

// inline homeHandler::homeHandler(string filePath) : TemplateHandler(filePath), data(_data) {}

// map<string, string> homeHandler::handle(Request *req) 
// {
//  	int userId = req->getSessionId();
//   	if (!data->find_user(userId)->is_publisher())
//   	{
//   		pair.first = false;
//   		pair.second = getHomeFilms(userId);
//   	}
//   	context = getHomeFilms(userId);
//   	else
//   	{
//   		pair.first = true;
//   		pair.second = getPublishedFilms(userId);
//   	}
//   	return pair;
// }

// vector<FilmInfo> homeHandler::getPublishedFilms(int userId)
// {
// 	return (Publisher*)(data->find_user(userId))->get_published_films();
// }

// vector<FilmInfo> homeHandler::getHomeFilms(int userId)
// {
// 	vector<FilmInfo> filmsInfo;
// 	vector<Film*> films = data->get_films();
// 	for (int i = 0; i <films.size(); i++)
// 		if ((!films[i]->is_deleted()) && (data->find_user(userId)->check_can_buy_film(films[i]->get_price())))
// 			filmsInfo.push_back(films[i]->set_info());
// 	return filmsInfo;
// }

inline deleteFilmHandler::deleteFilmHandler(Data* _data)
{
	data = _data;
}

Response* deleteFilmHandler::callback(Request* req)
{
	userId = req->getSessionId(); 
	if (userId == EMPTY_SESSION_ID)
		throw server::Exception("You have to login first!");
	((Publisher*)(data->find_user(userId)))->delete_film(stoi(req->getBodyParam(FILM_ID)));
  	Response* res = Response::redirect("/home");
  	res->setSessionId(userId);
  	return res;
}
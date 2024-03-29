#include <iostream>
#include "Handlers.h"
#include "Data.h"
#include "User.h"
#include "Publisher.h"
#include "Film.h"
#include "Recommender.h"
#include "Comment.h"

using namespace std;

Response* SignupHandler::callback(Request* req)
{
	Response* res;
  	request = req;
  	if (checkSignupInfo() == username)
  		throw Server::Exception("This username exists in system");
  	else if (checkSignupInfo() == pass)
  		throw Server::Exception("Wrong password confirmation");
  	string sessionId = signup();
  	res = Response::redirect("/home");
  	res->setSessionId(sessionId);
  	return res;
}

signupErr SignupHandler::checkSignupInfo()
{
	if (request->getBodyParam(PASSWORD) != request->getBodyParam(PASSCONFIRM))
		return pass;
	if (data->find_user(request->getBodyParam(USERNAME)) != NULL)
		return username;
	return ok;
}

string SignupHandler::signup()
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
		userInfo[PUBLISHER] = _TRUE;
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

SignupHandler::SignupHandler(Data* _data)
{
	data = _data;
}

LoginHandler::LoginHandler(Data* _data)
{
	data = _data;
}

Response* LoginHandler::callback(Request* req)
{
	Response* res;
	if (!data->find_user(req->getBodyParam(USERNAME))->check_password(req->getBodyParam(PASSWORD)))
		throw Server::Exception("Wrong password");
  	res = Response::redirect("/home");
  	string sessionId = to_string(data->find_user(req->getBodyParam(USERNAME))->get_id());
  	res->setSessionId(sessionId);
  	return res;
}

Response* LogoutHandler::callback(Request* req)
{
	if (req->getSessionId() == EMPTY_SESSION_ID)
		throw Server::Exception("You have to login first!");
  	Response* res = Response::redirect("/");
  	res->setSessionId(EMPTY_SESSION_ID);
  	return res;
}

HomeHandler::HomeHandler(string filePath, Data* _data) : TemplateHandler(filePath), data(_data) {}

map<string, string> HomeHandler::handle(Request *req)  
{ 
	int userId = stoi(req->getSessionId());
	if (req->getSessionId() == EMPTY_SESSION_ID) 
		throw Server::Exception("You have to login first!");
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

map<string, string> changeVectorToMap(vector<FilmInfo> filmsInfo)
{
	map<string, string> info;
	info[SIZE] = to_string(filmsInfo.size());
	int size = filmsInfo.size();
	for (int i = 0; i < size; i++)
	{
		string num = to_string(i);
		info[NAME + num] = filmsInfo[i].name;
		info[ID + num] = to_string(filmsInfo[i].id);
		info[LENGTH + num] = to_string(filmsInfo[i].length);
		info[PRICE + num] = to_string(filmsInfo[i].price);
		info[RATE + num] = to_string(filmsInfo[i].rate);
		info[YEAR + num] = to_string(filmsInfo[i].year);
		info[DIRECTOR + num] = filmsInfo[i].director;
		info[SUMMARY + num] = filmsInfo[i].summary;
	}
	return info;
}

map<string, string> HomeHandler::getPublishedFilms(int userId)
{
	return changeVectorToMap(((Publisher*)(data->find_user(userId)))->get_published_films());
}

map<string, string> HomeHandler::getHomeFilms(int userId)
{
	vector<FilmInfo> filmsInfo;
	vector<Film*> films = data->get_films();
	int size = films.size();
	for (int i = 0; i < size; i++)
		if ((!films[i]->is_deleted()) && (data->find_user(userId)->check_can_buy_film(films[i])))
			filmsInfo.push_back(films[i]->set_info());
	return changeVectorToMap(filmsInfo);
}

DeleteFilmHandler::DeleteFilmHandler(Data* _data)
{
	data = _data;
}

Response* DeleteFilmHandler::callback(Request* req)
{
	string userId = req->getSessionId();
	if ((userId == EMPTY_SESSION_ID) || (!data->find_user(stoi(userId))->is_publisher()))
		throw Server::Exception("You have to login first!");
	((Publisher*)(data->find_user(stoi(userId))))->delete_film(stoi(req->getBodyParam(FILM_ID)));
  	Response* res = Response::redirect("/home");
  	res->setSessionId(userId);
  	return res;
}

AddFilmHandler::AddFilmHandler(Data* _data, Recommender* _recommender)
{
	data = _data;
	recommender = _recommender;
}

Response* AddFilmHandler::callback(Request* req)
{
	string userId = req->getSessionId();
	if ((userId == EMPTY_SESSION_ID) || (!data->find_user(stoi(userId))->is_publisher()))
		throw Server::Exception("You have to login first!");
	addFilm(req);
  	Response* res = Response::redirect("/home");
  	res->setSessionId(userId);
  	return res;
}

void AddFilmHandler::addFilm(Request* req)
{
	map<string, string> FilmInfo;
	FilmInfo[NAME] = req->getBodyParam(NAME);
	FilmInfo[LENGTH] = req->getBodyParam(LENGTH);
	FilmInfo[PRICE] = req->getBodyParam(PRICE);
	FilmInfo[YEAR] = req->getBodyParam(YEAR);
	FilmInfo[DIRECTOR] = req->getBodyParam(DIRECTOR);
	FilmInfo[SUMMARY] = req->getBodyParam(YEAR);
	FilmInfo[FILM_ID] = to_string(data->get_new_film_id());
	Film* new_film = ((Publisher*)(data->find_user(stoi(req->getSessionId()))))->add_film(FilmInfo);
	data->add_new_film(new_film);
	recommender->add_new_element_to_graph();
}

BuyHandler::BuyHandler(Data* _data, Recommender* _recommender)
{
	data = _data;
	recommender = _recommender;
}

Response* BuyHandler::callback(Request* req)
{
	string userId = req->getSessionId();
	if (userId == EMPTY_SESSION_ID)
		throw Server::Exception("You have to login first!");
	Film* film = data->find_film(stoi(req->getBodyParam(FILM_ID)));
	if (!data->find_user(stoi(userId))->buy_new_film(film))
		throw Server::Exception("Not enough money!");
	recommender->update_graph_after_buy_a_film(film, data->find_user(stoi(userId)));
  	Response* res = Response::redirect("/home");
  	res->setSessionId(userId);
  	return res;
}

IncreaseMoneyHandler::IncreaseMoneyHandler(Data* _data)
{
	data = _data;
}

Response* IncreaseMoneyHandler::callback(Request* req)
{
	string userId = req->getSessionId(); 
	if (userId == EMPTY_SESSION_ID)
		throw Server::Exception("You have to login first!");
	data->find_user(stoi(userId))->charge_account(stoi(req->getBodyParam(AMOUNT)));
	Response* res = Response::redirect("/profile");
  	res->setSessionId(userId);
  	return res;
}

CommentHandler::CommentHandler(Data* _data)
{
	data = _data;
}

Response* CommentHandler::callback(Request* req)
{
	string userId = req->getSessionId(); 
	if (userId == EMPTY_SESSION_ID)
		throw Server::Exception("You have to login first!");
	data->find_user(stoi(userId))->comment(stoi(req->getBodyParam(FILM_ID)), req->getBodyParam(CONTENT));
	Response* res = Response::redirect("/profile");
  	res->setSessionId(userId);
  	return res;
}

ProfileHandler::ProfileHandler(string filePath, Data* _data) : TemplateHandler(filePath), data(_data) 
{}

map<string, string> ProfileHandler::handle(Request *req) 
{
 	int userId = stoi(req->getSessionId());
 	if (req->getSessionId() == EMPTY_SESSION_ID)
 		throw Server::Exception("You have to login first!");
 	map<string, string> context = changeVectorToMap(data->find_user(userId)->get_bought_films());
   	return context;
}

RateHandler::RateHandler(Data* _data)
{
	data = _data;
}

Response* RateHandler::callback(Request* req)
{
	string userId = req->getSessionId(); 
	if (userId == EMPTY_SESSION_ID)
		throw Server::Exception("You have to login first!");
	data->find_user(stoi(userId))->
		rate_film(stoi(req->getBodyParam(FILM_ID)), stoi(req->getBodyParam(SCORE)));
	Response* res = Response::redirect("/profile");
  	res->setSessionId(userId);
  	return res;
}

FilterFilmsHandler::FilterFilmsHandler(string filePath, Data* _data)
 : TemplateHandler(filePath), data(_data) {}

map<string, string> FilterFilmsHandler::handle(Request *req) 
{
 	string userId = req->getSessionId();
	if ((userId == EMPTY_SESSION_ID) || (!data->find_user(stoi(userId))->is_publisher()))
 		throw Server::Exception("You have to login first!");
 	map<string, string> context = changeVectorToMap(((Publisher*)(data->find_user(stoi(userId))))->
 		get_filtered_films(req->getQueryParam(DIRECTOR)));
   	return context;
}

FilmDetailsHandler::FilmDetailsHandler(string filePath, Data* _data, Recommender* _recommender)
 : TemplateHandler(filePath)
 {
 	data = _data;
 	recommender = _recommender;
 }

map<string, string> FilmDetailsHandler::handle(Request *req) 
{
 	string userId = req->getSessionId();
 	if (userId == EMPTY_SESSION_ID)
 		throw Server::Exception("You have to login first!");
 	User* user = data->find_user(stoi(userId));
 	Film* film = data->find_film(stoi(req->getQueryParam(FILM_ID)));
 	vector<FilmInfo> filmsInfo = recommender->recommend_film(user, film);
 	context = changeVectorToMap(filmsInfo);
 	FilmInfo details = film->set_info();
 	addFilmInfoToMap(details);
 	vector<Comment*> comments = film->get_comments();
 	addCommentsToMap(comments);
   	return context;
}

void FilmDetailsHandler::addCommentsToMap(vector<Comment*> comments)
{
	int size = comments.size();
	string num;
	context[CM_SIZE] = to_string(size);
	for (int i = 0; i < size; i++)
	{
		num = to_string(i);
		context[CM + num] = comments[i]->get_content();
	}
}

void FilmDetailsHandler::addFilmInfoToMap(FilmInfo details)
{
	context[ID] = to_string(details.id);
 	context[NAME] = details.name;
 	context[LENGTH] = to_string(details.length);
 	context[PRICE] = to_string(details.price);
 	context[RATE] = to_string(details.rate);
 	context[YEAR] = to_string(details.year);
 	context[DIRECTOR] = details.director;
 	context[SUMMARY] = details.summary;
}
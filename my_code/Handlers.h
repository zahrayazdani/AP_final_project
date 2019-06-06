#ifndef HANDLERS_H
#define HANDLERS_H

#include <string>
#include <vector>
#include <utility>
#include <map>
#include "../server/server.hpp"
#include "define.h"

class Data;
class Recommender;
class Comment;

class SignupHandler : public RequestHandler
{
private:
	Request* request;
	Data* data;
	signupErr checkSignupInfo();
	std::string signup();
public:
	SignupHandler(Data* _data);
 	Response* callback(Request* req);
};

class LoginHandler : public RequestHandler
{
private:
	Data* data;
public:
	LoginHandler(Data* _data);
 	Response* callback(Request* req);	
};

class LogoutHandler : public RequestHandler
{
public:
 	Response* callback(Request* req);	
};

class HomeHandler : public TemplateHandler {
private:
	Data* data;
	std::map<std::string, std::string> getHomeFilms(int userId);
	std::map<std::string, std::string> getPublishedFilms(int userId);
public:
  HomeHandler(std::string filePath, Data* _data);
  std::map<std::string, std::string> handle(Request *req);
};

class DeleteFilmHandler : public RequestHandler
{
private:
	Data* data;
public:
	DeleteFilmHandler(Data* _data);
 	Response* callback(Request* req);	
};

class AddFilmHandler : public RequestHandler
{
private:
	Data* data;
	Recommender* recommender;
	void addFilm(Request* req);
public:
	AddFilmHandler(Data* _data, Recommender* _recommender);
 	Response* callback(Request* req);	
};

class filterFilmsHandler : public RequestHandler
{
public:
 	Response* callback(Request* req);	
};

class BuyHandler : public RequestHandler
{
private:
	Data* data;
	Recommender* recommender;
public:
	BuyHandler(Data* _data, Recommender* _recommender);
 	Response* callback(Request* req);	
};

class RateHandler : public RequestHandler
{
private:
	Data* data;
public:
	RateHandler(Data* _data);
 	Response* callback(Request* req);		
};

class IncreaseMoneyHandler : public RequestHandler
{
private:
	Data* data;
public:
	IncreaseMoneyHandler(Data* _data);
 	Response* callback(Request* req);		
};

class CommentHandler : public RequestHandler
{
private:
	Data* data;
public:
	CommentHandler(Data* _data);
 	Response* callback(Request* req);		
};

class ProfileHandler : public TemplateHandler {
private:
	Data* data;
public:
  ProfileHandler(std::string filePath, Data* _data);
  std::map<std::string, std::string> handle(Request *req);
};

class FilterFilmsHandler : public TemplateHandler {
private:
	Data* data;
public:
  FilterFilmsHandler(std::string filePath, Data* _data);
  std::map<std::string, std::string> handle(Request *req);
};

class FilmDetailsHandler : public TemplateHandler {
private:
	Recommender* recommender;
	Data* data;
	std::map<std::string, std::string> context;
	void addCommentsToMap(std::vector<Comment*> comments);
public:
  FilmDetailsHandler(std::string filePath, Data* _data, Recommender* _recommender);
  std::map<std::string, std::string> handle(Request *req);
};

#endif
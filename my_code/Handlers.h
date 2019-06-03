#ifndef HANDLERS_H
#define HANDLERS_H

#include <string>
#include <vector>
#include <utility>
#include <map>
#include "../server/server.hpp"
#include "define.h"

class Data;

class signupHandler : public RequestHandler
{
private:
	Request* request;
	Data* data;
	signupErr checkSignupInfo();
	std::string signup();
public:
	signupHandler(Data* _data);
 	Response* callback(Request* req);
};

class loginHandler : public RequestHandler
{
private:
	Data* data;
public:
	loginHandler(Data* _data);
 	Response* callback(Request* req);	
};

class logoutHandler : public RequestHandler
{
public:
 	Response* callback(Request* req);	
};

class homeHandler : public TemplateHandler {
private:
	Data* data;
	std::vector<FilmInfo> getHomeFilms(int userId);
	std::vector<FilmInfo> getPublishedFilms(int userId);
public:
  homeHandler(std::string filePath, Data* _data);
  std::map<std::string, std::string> handle(Request *req);
};

class deleteFilmHandler : public RequestHandler
{
private:
	Data* data;
public:
	deleteFilmHandler(Data* _data);
 	Response* callback(Request* req);	
};

#endif
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
	std::map<std::string, std::string> getHomeFilms(int userId);
	std::map<std::string, std::string> getPublishedFilms(int userId);
	std::map<std::string, std::string> changeVectorToMap(std::vector<filmInfo>)
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

class addFilmHandler : public RequestHandler
{
private:
	Data* data;
	Recommender* recommender;
	void addFilm(Request* req);
public:
	addFilmHandler(Data* _data, Recommender* _recommender);
 	Response* callback(Request* req);	
};

class filterFilmsHandler : public RequestHandler
{
public:
 	Response* callback(Request* req);	
};

class buyHandler : public RequestHandler
{
private:
	Data* data;
	Recommender* recommender;
public:
	buyHandler(Data* _data, Recommender* _recommender);
 	Response* callback(Request* req);	
};

class rateHandler : public RequestHandler
{
private:
	Data* data;
public:
	rateHandler(Data* _data);
 	Response* callback(Request* req);		
};

class increaseMoneyHandler : public RequestHandler
{
private:
	Data* data;
public:
	increaseMoneyHandler(Data* _data);
 	Response* callback(Request* req);		
};

class commentHandler : public RequestHandler
{
private:
	Data* data;
public:
	commentHandler(Data* _data);
 	Response* callback(Request* req);		
};

#endif
#ifndef HANDLERS_H
#define HANDLERS_H

#include <string>
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
}
#endif
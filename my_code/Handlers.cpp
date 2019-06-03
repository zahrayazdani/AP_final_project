#include <map>
#include "Handlers.h"
#include "Data.h"
#include "User.h"
#include "Publisher.h"

using namespace std;
//
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
  	res->setSessionId(sessionId);
  	return res;
}

Response* signupHandler::callback(Request* req)
{
	if (req->getSessionId() == EMPTY_SESSION_ID)
		throw server::Exception("You have to login first!");
  	Response* res = Response::redirect("/");
  	res->setSessionId(EMPTY_SESSION_ID);
  	return res;
}
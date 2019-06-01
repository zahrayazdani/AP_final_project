#include "Handlers.h"

using namespace std;

//controller doer data

Response* signupHandler::callback(Request* req) {
  	string username = req->getBodyParam("username");
 	string password = req->getBodyParam("password");
  	if (username == "root")
    	throw Server::Exception("Remote root access has been disabled.");
  	cout << "username: " << username << ",\tpassword: " << password << endl;
  	Response *res = Response::redirect("/rand");
  	res->setSessionId("SID");
  	return res;
}
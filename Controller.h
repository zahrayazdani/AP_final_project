#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <map>
#include <string>

class Data;

class Controller
{
private:
	Data* data;
public:
	Controller(Data* _data);
	void control_signup(std::map<std::string, std::string> command);
	void control_login(std::map<std::string, std::string> command);
};

#endif
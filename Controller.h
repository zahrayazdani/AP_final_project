#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <map>
#include <string>

class Data;

class Controller
{
private:
	Data* data;
	void does_user_have_film(int film_id);
public:
	Controller(Data* _data);
	void control_signup(std::map<std::string, std::string> command);
	void control_login(std::map<std::string, std::string> command);
	void control_add_film(std::map<std::string, std::string> command);
	void control_reply(std::map<std::string, std::string> command);
	void control_follow(std::map<std::string, std::string> command);
	void control_rate(std::map<std::string, std::string> command);
	void control_comment(std::map<std::string, std::string> command);
};

#endif
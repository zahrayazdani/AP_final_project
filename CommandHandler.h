#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <string>
#include <map>

class Controller;
class Data;
class Printer;
class User;

class CommandHandler
{
private:
	Printer* printer;
	Data* data;
	User* active_user;
	Controller* controller;
	std::map<std::string, std::string> curr_command;
	void handle_post_commands();
	void handle_put_commands();
	void handle_delete_commands();
	void handle_get_commands();
public:
	CommandHandler();
	void handle_command(std::map<std::string, std::string> _curr_command);
};

#endif
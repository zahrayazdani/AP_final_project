#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <string>
#include <map>

class CommandHandler;
class Data;
class Controller;

class Manager
{
private:
	CommandHandler* command_handler;
	Data* data;
	Controller* controller;
	std::map<std::string, std::string> curr_command;
	void run_command();
	void handle_post_commands();
	void handle_put_commands();
	void handle_delete_commands();
	void handle_get_commands();
public:
	Manager();
	void run();
};

#endif
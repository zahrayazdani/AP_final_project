#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <string>

class CommandHandler;
class Data;
class Controller;

class Manager
{
private:
	CommandHandler* command_handler;
	Data* data;
	Controller* controller;
	std::vector<std::string> curr_command;
public:
	Manager();
	void run();
};

#endif
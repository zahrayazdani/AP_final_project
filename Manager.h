#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <string>
#include <map>

class CommandHandler;
class Data;
class CommandParser;
class Printer;

class Manager
{
private:
	CommandHandler* command_handler;
	CommandParser* command_parser;
	std::map<std::string, std::string> curr_command;
public:
	Manager();
	void run();
};

#endif
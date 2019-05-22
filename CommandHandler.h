#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <string>
#include <map>

class Controller;
class Data;
class Printer;

class CommandHandler
{
private:
	Printer* printer;
	Data* data;
	Controller* controller;
	std::map<std::string, std::string> curr_command;
	void handle_post_commands();
	void handle_put_commands();
	void handle_delete_commands();
	void handle_get_commands();
	void handle_post_money_commands();
	void handle_get_films_commands();
	void signup();
	void login();
	void add_film();
	void reply();
	void follow();
	void rate();
	void comment();
	void charge_account();
	void edit_film();
public:
	CommandHandler();
	void handle_command(std::map<std::string, std::string> _curr_command);
};

#endif
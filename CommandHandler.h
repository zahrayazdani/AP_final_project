#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <string>
#include <map>
#include <vector>
#include "define.h"

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
	void delete_film();
	void delete_comment();
	void buy();
	void get_money_from_network();
	std::vector<FollowersInfo> get_followers();
	std::vector<FilmInfo> get_published_films();
	std::vector<FilmInfo> get_bought_films();
public:
	CommandHandler();
	void handle_command(std::map<std::string, std::string> _curr_command);
};

#endif
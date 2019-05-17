#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <string>

class CommandHandler;
class User;
class Publisher;
class Film;

class Manager
{
private:
	CommandHandler* command_handler;
	std::vector<User*> users;
	std::vector<Publisher*> publishers;
	std::vector<Film*> films;
	int signup_id;
	int film_id;
	User* active_user;
	std::vector<std::string> curr_command;
public:
	Manager();
	void run();
};

#endif
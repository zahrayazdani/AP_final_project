#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <vector>

class CommandHandler;
class User;
class Publisher;
class Film;

class GameManager
{
private:
	CommandHandler* command_handler;
	std::vector<User*> users;
	std::vector<Publisher*> publishers;
	std::vector<Film*> films;
public:
	GameManager();
	void run();
};

#endif
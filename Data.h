#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>

class User;
class Publisher;
class Film;

class Data
{
private:
	std::vector<User*> users;
	std::vector<Publisher*> publishers;
	std::vector<Film*> films;
	int signup_id;
	int film_id;
	User* active_user;
public:
	Data();
	bool does_user_exist(std::string username);
};

#endif
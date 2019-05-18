#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>

class User;
class Film;

class Data
{
private:
	std::vector<User*> users;
	std::vector<Film*> films;
	int signup_id;
	int film_id;
	User* active_user;
public:
	Data();
	User* find_user(std::string username);
	User* get_active_user();
};

#endif
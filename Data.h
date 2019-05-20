#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>
#include <map>

class User;
class Film;
class Publisher;

class Data
{
private:
	std::vector<User*> users;
	std::vector<Film*> films;
	int signup_id;
	int film_id;
	User* active_user;
	int network_money;
	std::map<Publisher*, int> publishers_money;
public:
	Data();
	User* find_user(std::string username);
	User* get_active_user();
};

#endif
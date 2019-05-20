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
	int user_id;
	int film_id;
	User* active_user;
	int network_money;
	std::map<Publisher*, int> publishers_money;
public:
	Data();
	User* find_user(std::string username);
	User* get_active_user();
	void change_active_user(User* new_active_user);
	void add_new_user(User* new_user);
	int get_new_user_id();
	int get_new_film_id();
};

#endif
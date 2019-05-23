#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>
#include <map>
#include "define.h"

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
	void delete_users();
	void delete_films();
public:
	Data();
	~Data();
	User* find_user(std::string username);
	User* find_user(int id);
	Film* find_film(int id);
	User* get_active_user();
	std::vector<Film*> get_films();
	int get_new_user_id();
	int get_new_film_id();
	void change_active_user(User* new_active_user);
	void add_new_user(User* new_user);
	void add_new_film(Film* new_film);
	User* increase_network_money(int film_id);
	void decrease_network_money(int money);
	std::vector<FilmInfo> search(std::map<std::string, std::string> info);
};

#endif
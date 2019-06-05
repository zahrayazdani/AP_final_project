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
	int user_id;
	int film_id;
	void delete_users();
	void delete_films();
public:
	Data();
	~Data();
	User* find_user(std::string username);
	User* find_user(int id);
	Film* find_film(int id);
	std::vector<Film*> get_films();
	int get_new_user_id();
	int get_new_film_id();
	void add_new_user(User* new_user);
	void add_new_film(Film* new_film);
};

#endif
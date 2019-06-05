#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <map>
#include <utility>
#include "define.h"

class Publisher;
class Film;
class Comment;

class User
{
protected:
	std::string username;
	std::string email;
	std::string password;
	int age;
	int id;
	bool publisher;
	std::vector<Film*> bought_films;
	int money;
public:
	User(std::map<std::string, std::string> info);
	std::string get_username();
	int get_id();
	std::vector<Film*> get_films();
	bool check_password(std::string pass);
	bool check_can_buy_film(Film* film);
	bool is_publisher();
	Film* find_film(int id);
	void comment(int film_id, std::string content);
	void charge_account(int amount);
	void rate_film(int film_id, int score);
	bool buy_new_film(Film* new_film);
	std::vector<FilmInfo> get_bought_films();
};

#endif
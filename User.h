#ifndef USER_H
#define USER_H

#include "define.h"
#include <string>
#include <vector>
#include <map>

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
	std::vector<Publisher*> following;
	std::vector<Film*> bought_films;
	int money;
	std::vector<std::vector<std::string>> readen_notifs;
	std::vector<std::string> unread_notifs;
public:
	User(std::map<std::string, std::string> info);
	std::string get_username();
	std::string get_email();
	int get_id();
	int get_new_comment_id();
	bool check_password(std::string pass);
	bool check_can_buy_film(int film_price);
	bool is_publisher();
	Film* find_film(int id);
	void add_new_notif(std::string notif);
	bool follow(Publisher* publisher);
	Publisher* find_publisher(std::string publisher_name);
	void comment(int film_id, std::string content);
	void charge_account(int amount);
	void rate_film(int film_id, int score);
	std::string buy_new_film(Film* new_film);
	std::vector<FilmInfo> get_bought_films(std::map<std::string, std::string> info);
	std::vector<std::string> get_notifs();
	std::vector<std::vector<std::string>> get_readen_notifs();
};

#endif
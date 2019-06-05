#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <vector>
#include <string>
#include <map>
#include "User.h"
#include "define.h"

class Film;

class Publisher : public User
{
private:
	std::vector<Film*> published_films;
	// std::vector<User*> followers;
	// int debt_money;
	// User* find_follower(std::string username);
public:
	Publisher(std::map<std::string, std::string> info);
	Film* find_published_film(int id);
	// Film* find_published_film(std::string film_name);
	// void add_follower(User* new_follower);
	Film* add_film(std::map<std::string, std::string> info);
	// void edit_film(std::map<std::string, std::string> info);
	void delete_film(int id);
	// void reply_comment(std::map<std::string, std::string> info);
	// void delete_comment(int film_id, int comment_id);
	// void send_add_film_notif();
	// void increase_debt(int film_price, int film_rate);
	// int get_money_from_network();
	// std::vector<FollowersInfo> get_followers();
	std::vector<FilmInfo> get_published_films();
	std::vector<FilmInfo> get_filtered_films(std::string director_name);
};

#endif
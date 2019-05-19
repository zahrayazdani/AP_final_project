#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <vector>
#include <string>
#include "User.h"
#include "define.h"

class Film;

class Publisher : public User
{
private:
	std::vector<Film*> published_films;
	std::vector<User*> followers;
	int money_from_films;
public:
	//Publisher();
	Film* find_published_film(int id);
	Film* add_film(std::vector<std::string> info);
	void edit_film(std::vector<std::string> info);
	void delete_film(int id);
	std::vector<FollowersInfo> get_followrs();
	//money
	std::vector<FilmInfo> get_published_films(std::vector<std::string> info);
	void reply_comment(std::vector<std::string> info);
	void delete_comment(std::vector<std::string> info);
};

#endif
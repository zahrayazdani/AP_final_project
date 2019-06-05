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
public:
	Publisher(std::map<std::string, std::string> info);
	Film* find_published_film(int id);
	Film* add_film(std::map<std::string, std::string> info);
	void delete_film(int id);
	std::vector<FilmInfo> get_published_films();
	std::vector<FilmInfo> get_filtered_films(std::string director_name);
};

#endif
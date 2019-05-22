#ifndef PRINTER_H
#define PRINTER_H

#include <vector>
#include <string>
#include "define.h"

class Film;

class Printer
{
public:
	void print_success_message();
	void print_followers(std::vector<FollowersInfo> followers);
	void print_films(std::vector<FilmInfo> films);
	void print_notifs(std::vector<std::string> notifs);
	void print_readen_notifs(std::vector<std::string> notifs ,int limit);
	void print_film_details(Film* film);
	void print_recommend_films(std::vector<FilmInfo> recommends);
};

#endif
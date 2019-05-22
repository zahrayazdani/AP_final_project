#ifndef PRINTER_H
#define PRINTER_H

#include <vector>
#include <string>
#include "define.h"

class Film;

class Printer
{
private:
	bool compare_by_user_id(const FollowersInfo& num1, const FollowersInfo& num2);
	bool compare_by_film_id(const FilmInfo& num1, const FilmInfo& num2);
public:
	void print_success_message();
	void print_followers(std::vector<FollowersInfo> followers);
	void print_films(std::vector<FilmInfo> films);
	void print_notifs(std::vector<std::string> notifs);
	void print_readen_notifs(std::vector<std::string> notifs ,int limit);
	void print_film_details(Film* film);
};

#endif
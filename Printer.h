#ifndef PRINTER_H
#define PRINTER_H

#include <vector>
#include "define.h"

class Printer
{
private:
	bool compare_by_user_id(const FollowersInfo& num1, const FollowersInfo& num2);
	bool compare_by_film_id(const FilmInfo& num1, const FilmInfo& num2);
public:
	void print_success_message();
	void print_followers(std::vector<FollowersInfo> followers);
	void print_published_films(std::vector<FilmInfo> films);
};

#endif
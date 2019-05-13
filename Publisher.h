#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "User.h"
#include <vector>

class Film;

class Publisher : public User
{
private:
	std::vector<Film*> published_films;
	std::vector<User*> followers;
	int money_from_films;
public:
	Publisher();
};

#endif
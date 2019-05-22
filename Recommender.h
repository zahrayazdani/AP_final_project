#ifndef RECOMMENDER_H
#define RECOMMENDER_H

#include "define.h"

class Data;
class User;
class Film;

class Recommender
{
private:
	Data* data;
	User* curr_user;
	std::vector<Film*> films;
	bool compare_by_rate(const Film* num1, const Film* num2);
	std::vector<FilmInfo> find_recommendation_films();
public:
	Recommender(Data* _data);
	std::vector<FilmInfo> recommend_film(User* user);
};

#endif
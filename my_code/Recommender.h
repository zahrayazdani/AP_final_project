#ifndef RECOMMENDER_H
#define RECOMMENDER_H

#include <vector>
#include <utility>
#include "define.h"

class Data;
class User;
class Film;

class Recommender
{
private:
	Data* data;
	std::vector<std::vector<int>> films_graph;
	std::vector<FilmInfo> find_recommendation_films(User* user, Film* film);
	std::vector<std::pair<int, int>> construct_vector_of_pairs(Film* film);
public:
	Recommender(Data* _data);
	std::vector<FilmInfo> recommend_film(User* user, Film* film);
	void add_new_element_to_graph();
	void update_graph_after_buy_a_film(Film* film, User* user);
};

#endif
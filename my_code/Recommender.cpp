#include <iostream>
#include <algorithm>
#include "User.h"
#include "Data.h"
#include "Recommender.h"
#include "Film.h"

using namespace std;

Recommender::Recommender(Data* _data)
{
	data = _data;
}

// bool compare_by_weight(pair<int, int> pair1, pair<int, int> pair2)
// {
// 	if (pair1.second == pair2.second)
// 		return pair1.first > pair2.first;
// 	return pair1.second < pair2.second;
// }

// vector<FilmInfo> Recommender::recommend_film(User* user, Film* film)
// {
// 	return find_recommendation_films(user, film);
// }

// vector<FilmInfo> Recommender::find_recommendation_films(User* user, Film* film)
// {
// 	vector<pair<int, int>> id_and_weights = construct_vector_of_pairs(film);
// 	vector<FilmInfo> recommendation_films;
// 	for (int i = id_and_weights.size() - 1; i >= 0; i--)
// 	{
// 		if (recommendation_films.size() == NUM_OF_RECOMMENDED_FILMS)
// 			return recommendation_films;
// 		if ((user->find_film(id_and_weights[i].first) == NULL) &&
// 			(data->find_film(id_and_weights[i].first) != NULL) &&
// 			(id_and_weights[i].first != film->get_id()))
// 			recommendation_films.push_back(data->find_film(id_and_weights[i].first)->set_info());
// 	}
// 	return recommendation_films;
// }

void Recommender::add_new_element_to_graph()
{

	vector<int> new_line;
	if (films_graph.size() == 0)
	{
		new_line.push_back(0);
		films_graph.push_back(new_line);
		return;
	}
	for (int i = 0; i < films_graph.size(); i++)
		films_graph[i].push_back(0);
	for (int i = 0; i < films_graph[0].size(); i++)
		new_line.push_back(0);
	films_graph.push_back(new_line);
}

// void Recommender::update_graph_after_buy_a_film(Film* film, User* user)
// {
// 	vector<Film*> bought_films = user->get_films();
// 	int film_index = film->get_id() - 1;
// 	int curr_film_index;
// 	for (int i = 0; i < bought_films.size(); i++)
// 	{
// 		curr_film_index = (bought_films[i]->get_id()) - 1;
// 		films_graph[film_index][curr_film_index]++;
// 		films_graph[curr_film_index][film_index]++;
// 	}
// }

// vector<pair<int, int>> Recommender::construct_vector_of_pairs(Film* film)
// {
// 	vector<pair<int, int>> pairs;
// 	pair<int, int> new_pair;
// 	int line_number = film->get_id() - 1;
// 	for (int i = 0; i < films_graph.size(); i++)
// 	{
// 		new_pair.first = i + 1;
// 		new_pair.second = films_graph[line_number][i];
// 		pairs.push_back(new_pair);
// 	}
// 	sort(pairs.begin(), pairs.end(), compare_by_weight);
// 	return pairs;
// }
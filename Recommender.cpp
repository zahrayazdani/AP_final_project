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

bool compare_by_rate(Film* num1, Film* num2)
{
	if (num1->get_rate() == num2->get_rate())
		return num1->get_year() > num2->get_year();
	return num1->get_rate() < num2->get_rate();
}

vector<FilmInfo> Recommender::recommend_film(User* user, Film* curr_film)
{
	film = curr_film;
	curr_user = user;
	films = data->get_films();
	sort(films.begin(), films.end(), compare_by_rate);
	return find_recommendation_films();
}

vector<FilmInfo> Recommender::find_recommendation_films()
{
	vector<FilmInfo> recommendation_films;
	for (int i = films.size() - 1; i >= 0; i--)
	{
		if (recommendation_films.size() == NUM_OF_RECOMMENDED_FILMS)
			return recommendation_films;
		if ((curr_user->find_film(films[i]->get_id()) == NULL) && (!films[i]->is_deleted()) &&
			(films[i] != film))
			recommendation_films.push_back(films[i]->set_info());
	}
	return recommendation_films;
}
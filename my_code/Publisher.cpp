#include <iostream>
#include <sstream>
#include "Publisher.h"
#include "Film.h"
#include "Comment.h"

using namespace std;

Publisher::Publisher(map<string, string> info)
 : User(info) {}

Film* Publisher::add_film(map<string, string> info)
{
	Film* new_film = new Film(info);
	published_films.push_back(new_film);
	return new_film;
}

Film* Publisher::find_published_film(int id)
{
	int size = published_films.size();
	for (int i = 0; i < size; i++)
		if ((published_films[i]->get_id() == id) && (!published_films[i]->is_deleted()))
			return published_films[i];
	return NULL;
}

void Publisher::delete_film(int id)
{
	find_published_film(id)->change_delete_stat();
}

vector<FilmInfo> Publisher::get_published_films()
{
	vector<FilmInfo> films_info;
	int size = published_films.size();
	for (int i = 0; i < size; i++)
		if (!published_films[i]->is_deleted())
			films_info.push_back(published_films[i]->set_info());
	return films_info;
}

vector<FilmInfo> Publisher::get_filtered_films(string director_name)
{
	vector<FilmInfo> films_info;
	int size = published_films.size();
	for (int i = 0; i < size; i++)
		if ((!published_films[i]->is_deleted()) && (published_films[i]->get_director() == director_name))
			films_info.push_back(published_films[i]->set_info());
	return films_info;
}
#include <iostream>
#include "Exceptions.h"
#include "Publisher.h"
#include "Film.h"

// publisher code
using namespace std;

Film* Publisher::add_film(vector<string> info)
{
	info.push_back(USERNAME);
	info.push_back(username);
	Film* new_film = new Film(info);
}

vector<FollowersInfo> Publisher::get_followrs()
{
	vector<FollowersInfo> followers_info;
	FollowersInfo follower;
	for (int i = 0; i < followers.size(); i++)
	{
		follower.user_id = followers[i]->get_id();
		follower.username = followers[i]->get_username();
		follower.email = followers[i]->get_email();
		followers_info.push_back(follower);
	}
	return followers_info;
}

Film* Publisher::find_published_film(int id)
{
	for (int i = 0; i < published_films.size(); i++)
		if ((published_films[i]->get_id() == id) && (!published_films[i]->is_deleted()))
			return published_films[i];
	return NULL;
}

Film* publisher::find_published_film(string film_name)
{
	for (int i = 0; i < published_films.size(); i++)
		if (published_films[i]->get_name() == film_name)
			return published_films[i];
	return NULL;
}

void Publisher::delete_comment(vector<string> info)
{
	Film* film;
	try
	{
		film = find_published_film(stoi(info[3]));
	}catch (exception& exception)
	{
		cout << exception.what() << endl;
		return;
	}
	film->delete_comment(stoi(info[5]));
}

void Publisher::reply_comment(vector<string> info)
{
	Film* film;
	try
	{
		film = find_published_film(stoi(info[3]));
	}catch (exception& exception)
	{
		cout << exception.what() << endl;
		return;
	}
	film->reply_comment(stoi(info[5]), info[7]);
}

void Publisher::delete_film(int id)
{
	Film* film;
	try
	{
		film = find_published_film(id);
	}catch (exception& exception)
	{
		cout << exception.what() << endl;
		return;
	}
	delete film;
}

void Publisher::edit_film(vector<string> info)
{
	Film* film;
	try
	{
		film = find_published_film(stoi(info[3]));
	}catch (exception& exception)
	{
		cout << exception.what() << endl;
		return;
	}
	film->edit_info(info);
}

vector<FilmInfo> Publisher::get_published_films(vector<string> info)
{
	vector<FilmInfo> films_info;
	for (int i = 0; i < published_films.size(); i++)
		if (published_films[i]->is_in_range(info))
			films_info.push_back(published_films[i]->set_info());
}
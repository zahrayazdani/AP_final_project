#include <iostream>
#include "Exceptions.h"
#include "Publisher.h"
#include "Film.h"
#include "define.h"
#include "Comment.h"

using namespace std;

Publisher::Publisher(map<string, string> info)
 : User(info) {}

Film* Publisher::add_film(map<string, string> info)
{
	info[PUBLISHER] = username;
	Film* new_film = new Film(info);
	published_films.push_back(new_film);
	send_add_film_notif();
	return new_film;
}

// vector<FollowersInfo> Publisher::get_followrs()
// {
// 	vector<FollowersInfo> followers_info;
// 	FollowersInfo follower;
// 	for (int i = 0; i < followers.size(); i++)
// 	{
// 		follower.user_id = followers[i]->get_id();
// 		follower.username = followers[i]->get_username();
// 		follower.email = followers[i]->get_email();
// 		followers_info.push_back(follower);
// 	}
// 	return followers_info;
// }

Film* Publisher::find_published_film(int id)
{
	for (int i = 0; i < published_films.size(); i++)
		if ((published_films[i]->get_id() == id) && (!published_films[i]->is_deleted()))
			return published_films[i];
	return NULL;
}

Film* Publisher::find_published_film(string film_name)
{
	for (int i = 0; i < published_films.size(); i++)
		if (published_films[i]->get_name() == film_name)
			return published_films[i];
	return NULL;
}

// void Publisher::delete_comment(map<string, string> info)
// {
// 	Film* film;
// 	try
// 	{
// 		film = find_published_film(stoi(info[3]));
// 	}catch (exception& exception)
// 	{
// 		cout << exception.what() << endl;
// 		return;
// 	}
// 	film->delete_comment(stoi(info[5]));
// }

void Publisher::reply_comment(map<string, string> info)
{
	find_published_film(stoi(info[FILM_ID]))->reply_comment(stoi(info[COMMENT_ID]), info[CONTENT]);
	string notif;
	notif += "Publisher ";
	notif += username;
	notif += " with id ";
	notif += id;
	notif += " reply to your comment.";
	string comment_writer = find_published_film(stoi(info[FILM_ID]))->
		find_comment(stoi(info[COMMENT_ID]))->get_writer();
	///////////////////////////////////////
}

// void Publisher::delete_film(int id)
// {
// 	Film* film;
// 	try
// 	{
// 		film = find_published_film(id);
// 	}catch (exception& exception)
// 	{
// 		cout << exception.what() << endl;
// 		return;
// 	}
// 	delete film;
// }

// void Publisher::edit_film(map<string, string> info)
// {
// 	Film* film;
// 	try
// 	{
// 		film = find_published_film(stoi(info[3]));
// 	}catch (exception& exception)
// 	{
// 		cout << exception.what() << endl;
// 		return;
// 	}
// 	film->edit_info(info);
// }

// vector<FilmInfo> Publisher::get_published_films(map<string, string> info)
// {
// 	vector<FilmInfo> films_info;
// 	for (int i = 0; i < published_films.size(); i++)
// 		if (published_films[i]->is_in_range(info))
// 			films_info.push_back(published_films[i]->set_info());
// }

void Publisher::send_add_film_notif()
{
	string notif;
	notif += "Publisher ";
	notif += username;
	notif += " with id ";
	notif += id;
	notif += " register new film.";
	for (int i = 0; i < followers.size(); i++)
		followers[i]->add_new_notif(notif);
}
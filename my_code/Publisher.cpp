#include <iostream>
#include <sstream>
// #include "Exceptions.h"
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

// User* Publisher::find_follower(string username)
// {
// 	for (int i = 0; i < followers.size(); i++)
// 		if (followers[i]->get_username() == username)
// 			return followers[i];
// }

// vector<FollowersInfo> Publisher::get_followers()
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
	int size = published_films.size();
	for (int i = 0; i < size; i++)
		if ((published_films[i]->get_id() == id) && (!published_films[i]->is_deleted()))
			return published_films[i];
	return NULL;
}

// Film* Publisher::find_published_film(string film_name)
// {
// 	for (int i = 0; i < published_films.size(); i++)
// 		if ((published_films[i]->get_name() == film_name) && (!published_films[i]->is_deleted()))
// 			return published_films[i];
// 	return NULL;
// }

// void Publisher::delete_comment(int film_id, int comment_id)
// {
// 	find_published_film(film_id)->delete_comment(comment_id);
// }

// void Publisher::reply_comment(map<string, string> info)
// {
// 	find_published_film(stoi(info[FILM_ID]))->reply_comment(stoi(info[COMMENT_ID]), info[CONTENT]);
// 	stringstream notif;
// 	notif << "Publisher " << username << " with id " << id << " reply to your comment.";
// 	string comment_writer = find_published_film(stoi(info[FILM_ID]))->
// 		find_comment(stoi(info[COMMENT_ID]))->get_writer();
// 	find_follower(comment_writer)->add_new_notif(notif.str());
// }

void Publisher::delete_film(int id)
{
	find_published_film(id)->change_delete_stat();
}

// void Publisher::edit_film(map<string, string> info)
// {
// 	find_published_film(stoi(info[FILM_ID]))->edit_info(info);
// }

vector<FilmInfo> Publisher::get_published_films()
{
	vector<FilmInfo> films_info;
	int size = published_films.size();
	for (int i = 0; i < size; i++)
		if (!published_films[i]->is_deleted())
			films_info.push_back(published_films[i]->set_info());
	return films_info;
}

// void Publisher::send_add_film_notif()
// {
// 	stringstream notif;
// 	notif << "Publisher " << username << " with id " << id << " register new film.";
// 	for (int i = 0; i < followers.size(); i++)
// 		followers[i]->add_new_notif(notif.str());
// }

// void Publisher::increase_debt(int film_price, int film_rate)
// {
// 	if (film_rate < LOW_RATE)
// 		debt_money += 0.8 * film_price;
// 	else if (film_rate >= HIGH_RATE)
// 		debt_money += 0.95 * film_price;
// 	else
// 		debt_money += 0.9 * film_price;
// }

// int Publisher::get_money_from_network()
// {
// 	int temp = debt_money;
// 	money += debt_money;
// 	debt_money = 0;
// 	return temp;
// }

// void Publisher::add_follower(User* new_follower)
// {
// 	followers.push_back(new_follower);
// }

vector<FilmInfo> get_filtered_films(string director_name)
{
	vector<FilmInfo> films_info;
	int size = published_films.size();
	for (int i = 0; i < size; i++)
		if ((!published_films[i]->is_deleted()) && (published_films[i]->get_director() == director_name))
			films_info.push_back(published_films[i]->set_info());
	return films_info;
}
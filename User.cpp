#include <sstream>
#include "User.h"
#include "Publisher.h"
#include "Film.h"
#include "Comment.h"

using namespace std;

User::User(map<string, string> info)
{
	username = info[USERNAME];
	password = info[PASSWORD];
	email = info[EMAIL];
	age = stoi(info[AGE]);
	id = stoi(info[USER_ID]);
	if (info[PUBLISHER] == _TRUE)
		publisher = true;
	else
		publisher = false;
	money = 0;
}

string User::get_username()
{
	return username;
}

string User::get_email()
{
	return email;
}

int User::get_id()
{
	return id;
}

bool User::check_password(string pass)
{
	return pass == password;
}

bool User::is_publisher()
{
	return publisher;
}

Publisher* User::find_publisher(string publisher_name)
{
	for (int i = 0; i < following.size(); i++)
		if (following[i]->get_username() == publisher_name)
			return following[i];
	return NULL;
}

Film* User::find_film(int id)
{
	for (int i = 0; i < bought_films.size(); i++)
		if ((bought_films[i]->get_id() == id) && (!bought_films[i]->is_deleted()))
			return bought_films[i];
	return NULL;
}

void User::add_new_notif(string notif)
{
	unread_notifs.push_back(notif);
}

bool User::follow(Publisher* publisher)
{
	if (find_publisher(publisher->get_username()) == NULL)
	{
		following.push_back(publisher);
		return true;
	}
}

void User::rate_film(int film_id, int score)
{
	stringstream notif;
	notif << "User " << username << " with id " << id << " rate your film " <<
		find_film(film_id)->get_name() << " with id " << film_id;
	string publisher = find_film(film_id)->add_new_rate(score);
	find_publisher(publisher)->add_new_notif(notif.str());
}

void User::comment(int film_id, string content)
{
	stringstream notif;
	notif << "User " << username << " with id " << id << " comment on your film" <<
		find_film(film_id)->get_name() << " with id " << film_id;
	string publisher_name = find_film(film_id)->add_new_comment(content, username);
	find_publisher(publisher_name)->add_new_notif(notif.str());
}

void User::charge_account(int amount)
{
	money += amount;
}

bool User::check_can_buy_film(int film_price)
{
	if (film_price > money)
		return false;
}

string User::buy_new_film(Film* new_film)
{
	if (find_film(new_film->get_id()) == NULL)
	{
		bought_films.push_back(new_film);
		stringstream notif;
		notif << "User " << username << " with id " << id << " buy your film " << new_film->get_name() <<
			" with id " << new_film->get_id();
		return notif.str();
	}
	return EMPTY_STRING;
}

vector<FilmInfo> User::get_bought_films(map<string, string> info)
{
	vector<FilmInfo> films_info;
	for (int i = 0; i < bought_films.size(); i++)
		if (bought_films[i]->is_in_range(info) && (!bought_films[i]->is_deleted()))
			films_info.push_back(bought_films[i]->set_info());
}

vector<string> User::get_notifs()
{
	vector<string> temp = unread_notifs;
	transfer_unread_notifs_to_readen();
	empty_unread_notifs();
	return temp;
}

vector<string> User::get_readen_notifs()
{
	return readen_notifs;
}

void User::transfer_unread_notifs_to_readen()
{
	for (int i = 0; i < unread_notifs.size(); i++)
		readen_notifs.push_back(unread_notifs[i]);
}

void User::empty_unread_notifs()
{
	for (int i = 0; i < unread_notifs.size(); i++)
		unread_notifs.pop_back();
}
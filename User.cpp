#include "User.h"
#include "Publisher.h"
#include "Film.h"
#include "Comment.h"
#include "define.h"

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

void User::follow(Publisher* publisher)
{
	following.push_back(publisher);
}

void User::rate_film(int film_id, int score)
{
	stringstream notif;
	notif << "User " << username << " with id " << id << " rate your film " <<
		find_film(film_id)->get_name() << " with id " << film_id;
	string publisher = find_film(film_id)->add_new_rate(score);
	find_publisher(publisher)->add_new_notif(notif);
}
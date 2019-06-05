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

Film* User::find_film(int id)
{
	int size = bought_films.size();
	for (int i = 0; i < size; i++)
		if ((bought_films[i]->get_id() == id) && (!bought_films[i]->is_deleted()))
			return bought_films[i];
	return NULL;
}

void User::rate_film(int film_id, int score)
{
	find_film(film_id)->add_new_rate(score, username);
}

void User::comment(int film_id, string content)
{
	find_film(film_id)->add_new_comment(content);
}

void User::charge_account(int amount)
{
	money += amount;
}

bool User::check_can_buy_film(Film* film)
{
	if ((film->get_price() > money) || (find_film(film->get_id()) != NULL))
		return false;
	return true;
}

bool User::buy_new_film(Film* new_film)
{
	if (!check_can_buy_film(new_film))
		return false;
	bought_films.push_back(new_film);
	money -= new_film->get_price();
	return true;
}

vector<FilmInfo> User::get_bought_films()
{
	vector<FilmInfo> films_info;
	int size = bought_films.size();
	for (int i = 0; i < size; i++)
		films_info.push_back(bought_films[i]->set_info());
	return films_info;
}

vector<Film*> User::get_films()
{
	return bought_films;
}
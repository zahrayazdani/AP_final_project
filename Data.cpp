#include "Data.h"
#include "User.h"
#include "Film.h"
#include "Publisher.h"

using namespace std;

Data::Data()
{
	user_id = FIRST_ID;
	film_id = FIRST_ID;
	network_money = 0;
	active_user = NULL;
}

User* Data::find_user(string username)
{
	for (int i = 0; i < users.size(); i++)
		if (users[i]->get_username() == username)
			return users[i];
	return NULL;
}

User* Data::find_user(int id)
{
	for (int i = 0; i < users.size(); i++)
		if (users[i]->get_id() == id)
			return users[i];
	return NULL;
}

Film* Data::find_film(int id)
{
	for (int i = 0; i < films.size(); i++)
		if ((films[i]->get_id() == id) && (!films[i]->is_deleted()))
			return films[i];
	return NULL;
}

User* Data::get_active_user()
{
	return active_user;
}

void Data::change_active_user(User* new_active_user)
{
	active_user = new_active_user;
}

void Data::add_new_user(User* new_user)
{
	users.push_back(new_user);
}

int Data::get_new_user_id()
{
	user_id++;
	return user_id;
}

int Data::get_new_film_id()
{
	film_id++;
	return film_id;
}

void Data::add_new_film(Film* new_film)
{
	films.push_back(new_film);
}

User* Data::increase_network_money(int film_id)
{
	string publisher_username = find_film(film_id)->get_publisher_username();
	int film_price = find_film(film_id)->get_price();
	int film_rate = find_film(film_id)->get_rate();
	network_money += film_price;
	((Publisher*)(find_user(publisher_username)))->increase_debt(film_price, film_rate);
	return find_user(publisher_username);
}

void Data::decrease_network_money(int money)
{
	network_money -= money;
}

vector<FilmInfo> Data::search(map<string, string> info)
{
	vector<FilmInfo> films_info;
	for (int i = 0; i < films.size(); i++)
		if (films[i]->is_in_range(info) && (!films[i]->is_deleted()))
			films_info.push_back(films[i]->set_info());
	return films_info;
}
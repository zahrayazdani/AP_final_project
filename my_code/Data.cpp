#include "Data.h"
#include "User.h"
#include "Film.h"
#include "Publisher.h"
#include "define.h"

using namespace std;

Data::Data()
{
	user_id = FIRST_ID;
	film_id = FIRST_ID;
}

Data::~Data()
{
	delete_users();
	delete_films();
}

void Data::delete_users()
{
	for (int i = 0; i < users.size(); i++)
		delete users[i];
}

void Data::delete_films()
{
	for (int i = 0; i < films.size(); ++i)
	{
		films[i]->delete_comments();
		delete films[i];
	}
}

User* Data::find_user(string username)
{
	int size = users.size();
	for (int i = 0; i < size; i++)
		if (users[i]->get_username() == username)
			return users[i];
	return NULL;
}

User* Data::find_user(int id)
{
	int size = users.size();
	for (int i = 0; i < size; i++)
		if (users[i]->get_id() == id)
			return users[i];
	return NULL;
}

Film* Data::find_film(int id)
{
	int size = films.size();
	for (int i = 0; i < size; i++)
		if ((films[i]->get_id() == id) && (!films[i]->is_deleted()))
			return films[i];
	return NULL;
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

vector<Film*> Data::get_films()
{
	return films;
}
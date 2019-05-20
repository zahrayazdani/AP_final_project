#include "Data.h"
#include "define.h"
#include "User.h"
#include "Film.h"
#include "Publisher.h"

using namespace std;

Data::Data()
{
	user_id = FIRST_ID;
	film_id = FIRST_ID;
	active_user = NULL;
}

User* Data::find_user(string username)
{
	for (i = 0; i < users.size(); i++)
		if (users[i]->get_username() == username)
			return users[i];
	return NULL;
}

User* Data::find_user(int id)
{
	for (i = 0; i < users.size(); i++)
		if (users[i]->get_id() == id)
			return users[i];
	return NULL;
}

Film* Data::find_film(int id)
{
	for (i = 0; i < films.size(); i++)
		if (films[i]->get_id() == id)
			return films[i];
	return NULL;
}

User* Data::get_active_user()
{
	return active_user;
}

void Data::change_active_user(User* new_active_user);
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
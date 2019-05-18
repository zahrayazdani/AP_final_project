#include "Data.h"
#include "define.h"
#include "User.h"
#include "Film.h"
#include "Publisher.h"

using namespace std;

Data::Data()
{
	signup_id = FIRST_ID;
	film_id = FIRST_ID;
	active_user = NULL;
}

bool Data::does_user_exist(string username)
{
	for (i = 0; i < users.size(); i++)
		if (users[i]->get_username() == username)
		return true;
}

User* Data::find_user(string username)
{
	for (i = 0; i < users.size(); i++)
		if (users[i]->get_username() == username)
		return users[i];
}
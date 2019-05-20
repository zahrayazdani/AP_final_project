#include <typeinfo>
#include "Controller.h"
#include "Data.h"
#include "Exceptions.h"
#include "User.h"

Controller::Controller(Data* _data)
{
	data = _data;
}

void Controller::control_signup(map<string, string> command)
{
	if ((command.find(USERNAME) == command.end()) ||
		(command.find(PASSWORD) == command.end()) ||
		(command.find(EMAIL) == command.end()) || 
		(command.find(AGE) == command.end()))
		throw BadRequest();
	if (typeid(command[AGE]) != typeid(int))
		throw BadRequest();
	if (data->find_user(command[USERNAME]) != NULL)
		throw BadRequest();
	if (command.size() > 6)
		throw BadRequest();
	if ((command.size() == 6) && (command.find(PUBLISHER) == command.end()))
		throw BadRequest();
	check_validataion_of_email(command[EMAIL]);
	if ((command.find(PUBLISHER) != command.end()) && ((command[PUBLISHER] != _TRUE) ||
		(command[PUBLISHER] != _FALSE)))
		throw BadRequest();
}

void check_validataion_of_email(string email)
{
	if (email.find(AT) == email.end())
		throw BadRequest();
	if (email.find(DOT, email.find(AT) + 1) == email.end())
		throw BadRequest();
}

void Controller::control_login(map<string, string> command)
{
	if (!data->does_user_exist(command[USERNAME]))
		throw NotFound();
	if ((command.find(USERNAME) == command.end()) ||
		(command.find(PASSWORD) == command.end()))
		throw BadRequest();
	if (command.size() > 3)
		throw BadRequest();
	if (!data->find_user(command[USERNAME])->check_password(command[PASSWORD]))
		throw BadRequest();
}

void Controller::control_add_film(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (!data->get_active_user()->is_publisher())
		throw PermissionDenied();
	if ((command.find(NAME) == command.end()) ||
		(command.find(YEAR) == command.end()) ||
		(command.find(LENGTH) == command.end()) || 
		(command.find(PRICE) == command.end()) ||
		(command.find(SUMMARY) == command.end()) ||
		(command.find(DIRECTOR) == command.end()))
		throw BadRequest();
	if (command.size() > 7)
		throw BadRequest();
	if ((typeid(command[YEAR]) != typeid(int)) || (typeid(command[LENGTH]) != typeid(int)) ||
		(typeid(command[PRICE]) != typeid(int)))
		throw BadRequest();
	if (data->get_active_user()->find_published_film(command[NAME]) != NULL)
		throw BadRequest();
}

void Controller::control_reply(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (!data->get_active_user()->is_publisher())
		throw PermissionDenied();
	if ((command.find(FILM_ID) == command.end()) ||
		(command.find(COMMENT_ID) == command.end()) ||
		(command.find(CONTENT) == command.end()))
		throw BadRequest();
	if (command.size() > 4)
		throw BadRequest();
	if ((typeid(command[FILM_ID]) != typeid(int)) || (typeid(command[COMMENT_ID]) != typeid(int)))
		throw BadRequest();
	if (data->find_film(stoi(command[FILM_ID])) == NULL)
		throw NotFound();
	if (data->get_active_user()->find_film(stoi(command[FILM_ID])) == NULL)
		throw PermissionDenied();
	if (data->get_active_user()->find_film(stoi(command[FILM_ID]))
		->find_comment(stoi(command[COMMENT_ID])) == 	NULL)
		throw NotFound();
}

void Controller::control_follow(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (command.find(USER_ID) == command.end())
		throw BadRequest();
	if (command.size() > 2)
		throw BadRequest();
	if (typeid(command[USER_ID]) != typeid(int))
		throw BadRequest();
	if (data->find_user(stoi(command[USER_ID])) == NULL)
		throw NotFound();
	if (!data->find_user(stoi(command[USER_ID]))->is_publisher())
		throw PermissionDenied();
}

void Controller::control_rate(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if ((command.find(FILM_ID) == command.end()) ||
		(command.find(SCORE) == command.end()))
		throw BadRequest();
	if (command.size() > 3)
		throw BadRequest();
	if ((typeid(command[FILM_ID]) != typeid(int)) || (typeid(command[SCORE]) != typeid(int)))
		throw BadRequest();
	if (stoi((command[SCORE]) > MAX_SCORE) || stoi((command[SCORE]) < MIN_SCORE))
		throw BadRequest();
	does_user_have_the_film(stoi(command[FILM_ID]));
}

void Controller::control_comment(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if ((command.find(FILM_ID) == command.end()) ||
		(command.find(CONTENT) == command.end()))
		throw BadRequest();
	if (command.size() > 3)
		throw BadRequest();
	if (typeid(command[FILM_ID]) != typeid(int))
		throw BadRequest();
	does_user_have_the_film(stoi(command[FILM_ID]));
}

void Controller::does_user_have_the_film(int film_id)
{
	if (data->find_film(film_id) == NULL)
		throw BadRequest();
	if (data->get_active_user()->find_film(film_id) == NULL)
		throw PermissionDenied();
}

void Controller::control_edit_film(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (!data->get_active_user()->is_publisher())
		throw PermissionDenied();
	if (command.find(FILM_ID) == command.end())
		throw BadRequest();
	if (command.size() > 7)
		throw BadRequest();
	if (typeid(command[FILM_ID]) != typeid(int))
		throw BadRequest();
	check_edit_film_optional_datas(command);
	if (data->find_film(stoi(command[FILM_ID])) == NULL)
		throw NotFound();
	if (data->get_active_user()->find_published_film(stoi(command[FILM_ID])) == NULL)
		throw PermissionDenied();
}

void Controller::check_edit_film_optional_datas(map<string, string> command)
{
	for (map<string, string>::iterator it = command.begin(); it != command.end(); ++it)
	{
		if ((it->first != NAME) && (it->first != YEAR) && (it->first != LENGTH) &&
			(it->first != SUMMARY) && (it->first != DIRECTOR))
			throw BadRequest();
		if (((it->first == YEAR) && (typeid(it->second) != typeid(int))) ||
			((it->first == LENGTH) && (typeid(it->second) != typeid(int))))
			throw BadRequest();
	}
}

void Controller::control_delete_film(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (!data->get_active_user()->is_publisher())
		throw PermissionDenied();
	if (command.find(FILM_ID) == command.end())
		throw BadRequest();
	if (command.size() > 2)
		throw BadRequest();
	if (typeid(command[FILM_ID]) != typeid(int))
		throw BadRequest();
	if (data->find_film(stoi(command[FILM_ID])) == NULL)
		throw NotFound();
	if (data->get_active_user()->find_published_film(stoi(command[FILM_ID])) == NULL)
		throw PermissionDenied();
}

void Controller::control_delete_comment(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (!data->get_active_user()->is_publisher())
		throw PermissionDenied();
	if ((command.find(FILM_ID) == command.end()) ||
		(command.find(COMMENT_ID) == command.end()))
		throw BadRequest();
	if (command.size() > 3)
		throw BadRequest();
	if ((typeid(command[FILM_ID]) != typeid(int)) || (typeid(command[COMMENT_ID]) != typeid(int)))
		throw BadRequest();
	if (data->find_film(stoi(command[FILM_ID])) == NULL)
		throw NotFound();
	if (data->get_active_user()->find_film(stoi(command[FILM_ID])) == NULL)
		throw PermissionDenied();
	if (data->get_active_user()->find_film(stoi(command[FILM_ID]))
		->find_comment(stoi(command[COMMENT_ID])) == 	NULL)
		throw NotFound();
}

void Controller::control_get_followers(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (!data->get_active_user()->is_publisher())
		throw PermissionDenied();
}

void Controller::control_get_published_films(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (!data->get_active_user()->is_publisher())
		throw PermissionDenied();
	if (command.size() > 7)
		throw BadRequest();
	check_search_films_optional_datas(command);
}

void Controller::check_search_films_optional_datas(map<string, string> command)
{
	for (map<string, string>::iterator it = command.begin(); it != command.end(); ++it)
	{
		if ((it->first != NAME) && (it->first != MINRATE) && (it->first != MAXYEAR) &&
			(it->first != MINYEAR) && (it->first != PRICE) && (it->first != DIRECTOR))
			throw BadRequest();
		if (((it->first == MINRATE) && (typeid(it->second) != typeid(int))) ||
			((it->first == MAXYEAR) && (typeid(it->second) != typeid(int))) ||
			(it->first == MINYEAR) && (typeid(it->second) != typeid(int)) ||
			((it->first == PRICE) && (typeid(it->second) != typeid(int))))
			throw BadRequest();
	}
}

void Controller::control_get_bought_films(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (command.size() > 6)
		throw BadRequest();
	check_get_bought_films_optional_datas(command);
}

void Controller::check_get_bought_films_optional_datas(map<string, string> command)
{
	for (map<string, string>::iterator it = command.begin(); it != command.end(); ++it)
	{
		if ((it->first != NAME) && (it->first != MAXYEAR) && (it->first != MINYEAR) &&
			(it->first != PRICE) && (it->first != DIRECTOR))
			throw BadRequest();
		if (((it->first == MAXYEAR) && (typeid(it->second) != typeid(int))) ||
			(it->first == MINYEAR) && (typeid(it->second) != typeid(int)) ||
			((it->first == PRICE) && (typeid(it->second) != typeid(int))))
			throw BadRequest();
	}
}

void Controller::control_get_notifs(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
}

void Controller::control_get_readen_notifs(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (command.find(LIMIT) == command.end())
		throw BadRequest();
	if (command.size() > 2)
		throw BadRequest();
}

void Controller::control_get_money_from_network(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (!data->get_active_user()->is_publisher())
		throw PermissionDenied();
	if (command.size() > 1)
		throw BadRequest();
}

void Controller::control_charge_account(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (command.size() > 2)
		throw BadRequest();
	if (typeid(command[AMOUNT]) != typeid(int))
		throw BadRequest();
}

void Controller::control_search(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (command.size() > 7)
		throw BadRequest();
	check_search_films_optional_datas(command);
}

void Controller::control_show_film_details(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (command.size() > 2)
		throw BadRequest();
	if (typeid(command[FILM_ID]) != typeid(int))
		throw BadRequest();
}
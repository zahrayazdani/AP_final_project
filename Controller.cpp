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
	if (data->find_user(command[USERNAME]) != NULL)
		throw BadRequest();
}

void Controller::control_login(map<string, string> command)
{
	if (!data->does_user_exist(command[USERNAME]))
		throw BadRequest();
	if ((command.find(USERNAME) == command.end()) ||
		(command.find(PASSWORD) == command.end()))
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
	if (data->find_user(stoi(command[USER_ID])) == NULL)
		throw BadRequest();
	if (!data->find_user(stoi(command[USER_ID]))->is_publisher())
		throw BadRequest();
}

void Controller::control_rate(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if ((command.find(FILM_ID) == command.end()) ||
		(command.find(SCORE) == command.end()))
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
	does_user_have_the_film(stoi(command[FILM_ID]));
}

void Controller::does_user_have_the_film(int film_id)
{
	if (data->find_film(film_id) == NULL)
		throw BadRequest();
	if (data->get_active_user()->find_film(film_id) == NULL)
		throw PermissionDenied();
}

void Controller::control_edit_or_delete_film(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw PermissionDenied();
	if (!data->get_active_user()->is_publisher())
		throw PermissionDenied();
	if (command.find(FILM_ID) == command.end())
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
}

void Controller::control_get_bought_films_and_notifs(map<string, string> command)
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
}
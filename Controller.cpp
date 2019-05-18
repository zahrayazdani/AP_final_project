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
	if ((command.find(USERNAME) == curr_command.end()) ||
		(command.find(PASSWORD) == curr_command.end()) ||
		(command.find(EMAIL) == curr_command.end()) || 
		(command.find(AGE) == curr_command.end()))
		throw BadRequest();
	if (data->find_user(command[USERNAME]) != NULL)
		throw BadRequest();
}

void Controller::control_login(map<string, string> command)
{
	if (!data->does_user_exist(command[USERNAME]))
		throw BadRequest();
	if ((command.find(USERNAME) == curr_command.end()) ||
		(command.find(PASSWORD) == curr_command.end()))
		throw BadRequest();
	if (!data->find_user(command[USERNAME])->check_password(command[PASSWORD]))
		throw BadRequest();
}

void Controller::control_add_film(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw BadRequest();
	if (!data->get_active_user()->is_publisher())
		throw BadRequest();
	if ((command.find(NAME) == curr_command.end()) ||
		(command.find(YEAR) == curr_command.end()) ||
		(command.find(LENGTH) == curr_command.end()) || 
		(command.find(PRICE) == curr_command.end()) ||
		(command.find(SUMMARY) == curr_command.end()) ||
		(command.find(DIRECTOR) == curr_command.end()))
		throw BadRequest();
	if (data->get_active_user()->find_film(command[NAME]) != NULL)
		throw BadRequest();
}

void Controller::control_reply(map<string, string> command)
{
	if (data->get_active_user() == NULL)
		throw BadRequest();
	if (!data->get_active_user()->is_publisher())
		throw BadRequest();
	if ((command.find(FILM_ID) == curr_command.end()) ||
		(command.find(COMMENT_ID) == curr_command.end()) ||
		(command.find(CONTENT) == curr_command.end()))
		throw BadRequest();
	if (data->get_active_user()->find_film(command[FILM_ID]) == NULL)
		throw BadRequest();
	if (data->get_active_user()->find_film(command[FILM_ID])->find_comment(command[COMMENT_ID])
		== 	NULL)
		throw BadRequest();
}
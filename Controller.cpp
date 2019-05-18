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
	
}
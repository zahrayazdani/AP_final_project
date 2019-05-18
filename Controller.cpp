#include "Controller.h"
#include "Data.h"
#include "Exceptions.h"

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
	if (data->does_user_exist(command[USERNAME]))
		throw BadRequest();
}
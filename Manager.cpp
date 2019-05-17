#include <iostream>
#include "CommandHandler.h"
#include "Manager.h"
#include "User.h"
#include "Film.h"
#include "Publisher.h"
#include "define.h"

using namespace std;

Manager::Manager()
{
	command_handler = new CommandHandler;
	signup_id = FIRST_ID;
	film_id = FIRST_ID;
	active_user = NULL;
}

void Manager::run()
{
	string input;
	while (getline(cin, input))
	{
		curr_command = command_handler->parse_command(input);
		// control_command;
		// do_command;
		// print;
	}
}


#include <iostream>
#include "CommandHandler.h"
#include "Manager.h"
#include "define.h"
#include "Data.h"
#include "Controller.h"

using namespace std;

Manager::Manager()
{
	command_handler = new CommandHandler;
	data = new Data();
	controller = new Controller(data);
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


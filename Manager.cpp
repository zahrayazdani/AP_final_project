#include <iostream>
#include "CommandHandler.h"
#include "Manager.h"
#include "Exceptions.h"
#include "CommandParser.h"

using namespace std;

Manager::Manager()
{
	command_handler = new CommandHandler();
	command_parser = new CommandParser;
}

void Manager::run()
{
	string input;
	while (getline(cin, input))
	{
		try
		{
			curr_command = command_parser->parse_command(input);
			command_handler->handle_command(curr_command);
		} catch (exception& exception)
		{
			cout << exception.what() << endl;
		}
	}
}
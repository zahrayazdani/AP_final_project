#include <iostream>
#include "CommandHandler.h"
#include "Manager.h"
#include "define.h"
#include "Data.h"
#include "Controller.h"
#include "Exceptions.h"
#include "Printer.h"

using namespace std;

Manager::Manager()
{
	command_handler = new CommandHandler;
	data = new Data();
	controller = new Controller(data);
	printer = new Printer;
}

void Manager::run()
{
	string input;
	while (getline(cin, input))
	{
		try
		{
			curr_command = command_handler->parse_command(input);
			run_command();
		} catch (exception& exception)
		{
			cout << exception.what() << endl;
		}
	}
}

void Manager::run_command()
{
	if (curr_command.find(POST) != curr_command.end())
		handle_post_commands();
	else if (curr_command.find(PUT) != curr_command.end()) 
		handle_put_commands();
	else if (curr_command.find(DELETE) != curr_command.end()) 
		handle_delete_commands();
	else if (curr_command.find(GET) != curr_command.end()) 
		handle_get_commands();
}

void Manager::handle_post_commands()
{

}

void Manager::handle_put_commands()
{
	
}

void Manager::handle_delete_commands()
{
	
}

void Manager::handle_get_commands()
{
	
}
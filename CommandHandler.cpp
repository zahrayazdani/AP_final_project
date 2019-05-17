#include "CommandHandler.h"
#include "Controller.h"
#include "Data.h"
#include "define.h"
#include "User.h"
#include "Printer.h"

using namespace std;

CommandHandler::CommandHandler()
{
	data = new Data;
	controller = new Controller(data);
	printer = new Printer;
	active_user = NULL;
}

void CommandHandler::handle_command(map<string, string> _curr_command)
{
	// curr_command = _curr_command;
	// if (curr_command.find(POST) != curr_command.end())
	// 	handle_post_commands();
	// else if (curr_command.find(PUT) != curr_command.end()) 
	// 	handle_put_commands();
	// else if (curr_command.find(DELETE) != curr_command.end()) 
	// 	handle_delete_commands();
	// else if (curr_command.find(GET) != curr_command.end()) 
	// 	handle_get_commands();
}
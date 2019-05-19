#include "CommandHandler.h"
#include "Controller.h"
#include "Data.h"
#include "define.h"
#include "Printer.h"
#include "Exceptions.h"

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
	curr_command = _curr_command;
	if (curr_command.find(POST) != curr_command.end())
		handle_post_commands();
	else if (curr_command.find(PUT) != curr_command.end()) 
		handle_put_commands();
	else if (curr_command.find(DELETE) != curr_command.end()) 
		handle_delete_commands();
	else if (curr_command.find(GET) != curr_command.end()) 
		handle_get_commands();
	else
		throw BadRequest();
}

//permission denied a koja?
//maghadire ba type namonaseb?
//buy a film poolesh che jorie? 
//money publisheram che jorie?
//2 ta name film mishe yeki bashan?
//klan noe exc
void CommandHandler::handle_post_commands()
{
	string command = curr_command[POST];
	if (command == SIGNUP)
	{
		controller->control_signup(curr_command);
		//email
		//badesh login
		// signup();
	}
	else if (command == LOGIN)
	{
		controller->control_login(curr_command);
		//login();
	}
	else if (command == FILMS)
	{
		controller->control_add_film(curr_command);
		//notif
		//add_film();
	}
	else if (command == MONEY)
	{
		//money();
	}
	else if (command == REPLIES)
	{
		controller->control_reply(curr_command);
		//notif
		//reply();
	}
	else if (command == FOLLOWERS)
	{
		controller->control_follow(curr_command);
		//notif
		//follow();
	}
	else if (command == BUY)
	{
		controller->control_buy(curr_command);
		//notif
		//buy();
	}
	else if (command == RATE)
	{
		controller->control_rate(curr_command);
		//notif
		//rate();
	}
	else if (command == COMMENTS)
	{
		controller->control_comment(curr_command);
		//notif
		//comment();
	}
	else
		throw NotFound();
	printer->print_success_message();
}

void CommandHandler::handle_put_commands()
{
	if (curr_command[PUT] == FILMS)
	{
		controller->control_edit_film_info(curr_command);
		//edit_film;
	}
	else
		throw NotFound();
	printer->print_success_message();
}

void CommandHandler::handle_delete_commands()
control_{
	if (curr_command[DELETE] == FILMS)
	{
		controller->control_delete_film(curr_command);
		//delete_film();
	}
	else if (curr_command[DELETE] == COMMENTS)
	{
		controller->control_delete_comment(curr_command);
		//delete_comment;
	}
	else
		throw NotFound();
	printer->print_success_message(curr_command);
}

void CommandHandler::handle_get_commands()
{
	string command = curr_command[POST];
	if (command == FOLLOWERS)
	{
		controller->control_get_followers(curr_command);
		//get_followers();
		//print
	}
	else if (command == PUBLISHED)
	{
		controller->control_get_published_films(curr_command);
		//get_published_films();
		//print
	}
	else if (command == FILMS)
	{
		//film
	}
	else if (command == PURCHASED)
	{
		controller->control_get_bought_films(curr_command);
		//get_bought_films();
		//print
	}
	else if (command == NOTIFS)
	{
		controller->control_get_notifs(curr_command);
		//get_notifs();
		//print
	}
	else if (command == READEN_NOTIFS)
	{
		controller->control_get_readen_notifs(curr_command);
		//get_readen_notifs();
		//print
	}
	else
		throw NotFound();
}
#include <sstream>
#include "CommandHandler.h"
#include "Controller.h"
#include "Data.h"
#include "define.h"
#include "Printer.h"
#include "Exceptions.h"
#include "User.h"
#include "Publisher.h"
#include "Film.h"

using namespace std;

CommandHandler::CommandHandler()
{
	data = new Data;
	controller = new Controller(data);
	printer = new Printer;
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

void CommandHandler::handle_post_commands()
{
	string command = curr_command[POST];
	if (command == SIGNUP)
	{
		controller->control_signup(curr_command);
		signup();
	}
	else if (command == LOGIN)
	{
		controller->control_login(curr_command);
		login();
	}
	else if (command == FILMS)
	{
		controller->control_add_film(curr_command);
		add_film();
	}
	else if (command == MONEY)
	{
		handle_post_money_commands();
	}
	else if (command == REPLIES)
	{
		controller->control_reply(curr_command);
		reply();
	}
	else if (command == FOLLOWERS)
	{
		controller->control_follow(curr_command);
		follow();
	}
	else if (command == BUY)
	{
		controller->control_buy(curr_command);
		//check pool
		//notif
		//buy();
	}
	else if (command == RATE)
	{
		controller->control_rate(curr_command);
		rate();
	}
	else if (command == COMMENTS)
	{
		controller->control_comment(curr_command);
		comment();
	}
	else
		throw NotFound();
	printer->print_success_message();
}

void CommandHandler::handle_post_money_commands()
{
	if (curr_command.find(AMOUNT) == curr_command.end())
	{
		controller->control_get_money_from_network(curr_command);
		//get_money
	}
	else
	{
		controller->control_charge_account(curr_command);
		charge_account();
	}
}

void CommandHandler::handle_put_commands()
{
	if (curr_command[PUT] == FILMS)
	{
		controller->control_edit_film(curr_command);
		//edit_film;
	}
	else
		throw NotFound();
	printer->print_success_message();
}

void CommandHandler::handle_delete_commands()
{
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
	printer->print_success_message();
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
		handle_get_films_commands();
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

void CommandHandler::handle_get_films_commands()
{
	if (curr_command.find(FILM_ID) == curr_command.end())
	{
		controller->control_search(curr_command);
		//search;
		//print
	}
	else
	{
		controller->control_show_film_details(curr_command);
		//show_details;
		//print
		//recomend
	}
}

void CommandHandler::signup()
{
	curr_command[USER_ID] = to_string(data->get_new_user_id());
	User* new_user;
	if ((curr_command.find(PUBLISHER) != curr_command.end()) && (curr_command[PUBLISHER] == _TRUE))
		new_user = new Publisher(curr_command);
	else
	{
		curr_command[PUBLISHER] = _FALSE;
		new_user = new User(curr_command);
	}
	data->add_new_user(new_user);
	data->change_active_user(new_user);
}

void CommandHandler::login()
{
	User* new_login = data->find_user(curr_command[USERNAME]);
	data->change_active_user(new_login);
}

void CommandHandler::add_film()
{
	curr_command[FILM_ID] = to_string(data->get_new_film_id());
	Film* new_film = ((Publisher*)(data->get_active_user()))->add_film(curr_command);
	data->add_new_film(new_film);
}

void CommandHandler::reply()
{
	((Publisher*)(data->get_active_user()))->reply_comment(curr_command);
}

void CommandHandler::follow()
{
	User* curr_user = data->get_active_user();
	stringstream notif;
	notif << "User " << curr_user->get_username() << " with id "  << curr_user->get_id() <<
		 " follow you.";
	curr_user->follow((Publisher*)(data->find_user(stoi(curr_command[USER_ID]))));
	data->find_user(stoi(curr_command[USER_ID]))->add_new_notif(notif.str());
}

void CommandHandler::rate()
{
	data->get_active_user()->rate_film(stoi(curr_command[FILM_ID]), stoi(curr_command[SCORE]));	
}

void CommandHandler::comment()
{
	data->get_active_user()->comment(stoi(curr_command[FILM_ID]), curr_command[CONTENT]);
}

void CommandHandler::charge_account()
{
	data->get_active_user()->charge_account(stoi(curr_command[AMOUNT]));
}
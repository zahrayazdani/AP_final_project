#include <sstream>
#include "CommandHandler.h"
#include "Controller.h"
#include "Data.h"
#include "Printer.h"
#include "Exceptions.h"
#include "User.h"
#include "Publisher.h"
#include "Film.h"
#include "Recommender.h"
#include "Admin.h"

using namespace std;

CommandHandler::CommandHandler()
{
	data = new Data;
	controller = new Controller(data);
	printer = new Printer;
	recommender = new Recommender(data);
	admin = new Admin(data);
}

CommandHandler::~CommandHandler()
{
	delete data;
	delete controller;
	delete printer;
	delete recommender;
	delete admin;
}

void CommandHandler::handle_command(map<string, string> _curr_command)
{
	curr_command = _curr_command;
	if (curr_command.size() == 0)
		return;
	if (curr_command.find(POST) != curr_command.end())
		handle_post_commands();
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
		controller->control_signup(curr_command, admin->get_active());
		signup();
	}
	else if (command == LOGIN)
	{
		controller->control_login(curr_command, admin);
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
		buy();
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
	else if (command == PUT_FILMS)
	{
		controller->control_edit_film(curr_command);
		edit_film();
	}
	else if (command == DELETE_FILMS)
	{
		controller->control_delete_film(curr_command);
		delete_film();
	}
	else if (command == DELETE_COMMENTS)
	{
		controller->control_delete_comment(curr_command);
		delete_comment();
	}
	else if (command == LOGOUT)
	{
		controller->control_logout(curr_command, admin->get_active());
		logout();
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
		get_money_from_network();
	}
	else
	{
		controller->control_charge_account(curr_command);
		charge_account();
	}
}

void CommandHandler::handle_get_commands()
{
	string command = curr_command[GET];
	if (command == FOLLOWERS)
	{
		controller->control_get_followers(curr_command);
		printer->print_followers(get_followers());
	}
	else if (command == PUBLISHED)
	{
		controller->control_get_published_films(curr_command);
		printer->print_films(get_published_films());
	}
	else if (command == FILMS)
	{
		handle_get_films_commands();
	}
	else if (command == PURCHASED)
	{
		controller->control_get_bought_films(curr_command);
		printer->print_films(get_bought_films());
	}
	else if (command == NOTIFS)
	{
		controller->control_get_notifs(curr_command);
		printer->print_notifs(get_notifs());
	}
	else if (command == READ_NOTIFS)
	{
		controller->control_get_read_notifs(curr_command);
		printer->print_read_notifs(get_read_notifs(), stoi(curr_command[LIMIT]));
	}
	else if (command == MONEY)
	{
		controller->control_get_money(curr_command, admin->get_active());
		printer->print_amount_of_money(handle_get_money());
	}
	else
		throw NotFound();
}

void CommandHandler::handle_get_films_commands()
{
	if (curr_command.find(FILM_ID) == curr_command.end())
	{
		controller->control_search(curr_command);
		printer->print_films(search());
	}
	else
	{
		controller->control_show_film_details(curr_command);
		printer->print_film_details(data->find_film(stoi(curr_command[FILM_ID])));
		printer->print_recommended_films(recommender->recommend_film(data->get_active_user(), 
			data->find_film(stoi(curr_command[FILM_ID]))));
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
	if (curr_command[USERNAME] == ADMIN)
		admin->login();
	else
	{
		User* new_login = data->find_user(curr_command[USERNAME]);
		data->change_active_user(new_login);
	}
}

void CommandHandler::add_film()
{
	curr_command[FILM_ID] = to_string(data->get_new_film_id());
	Film* new_film = ((Publisher*)(data->get_active_user()))->add_film(curr_command);
	data->add_new_film(new_film);
	recommender->add_new_element_to_graph();
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
	if (curr_user->follow((Publisher*)(data->find_user(stoi(curr_command[USER_ID])))))
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

void CommandHandler::edit_film()
{
	((Publisher*)(data->get_active_user()))->edit_film(curr_command);
}

void CommandHandler::delete_film()
{
	((Publisher*)(data->get_active_user()))->delete_film(stoi(curr_command[FILM_ID]));
}

void CommandHandler::delete_comment()
{
	((Publisher*)(data->get_active_user()))->delete_comment(stoi(curr_command[FILM_ID]), 
		stoi(curr_command[COMMENT_ID]));
}

void CommandHandler::buy()
{
	Film* film = data->find_film(stoi(curr_command[FILM_ID]));
	string notif = data->get_active_user()->buy_new_film(film);
	if (notif != EMPTY_STRING)
	{
		recommender->update_graph_after_buy_a_film(film, data->get_active_user());
		User* publisher = data->increase_network_money(stoi(curr_command[FILM_ID]));
		publisher->add_new_notif(notif);
	}
}

void CommandHandler::get_money_from_network()
{
	int money = ((Publisher*)(data->get_active_user()))->get_money_from_network();
	data->decrease_network_money(money);
}

vector<FollowersInfo> CommandHandler::get_followers()
{
	return ((Publisher*)(data->get_active_user()))->get_followers();
}

vector<FilmInfo> CommandHandler::get_published_films()
{
	return ((Publisher*)(data->get_active_user()))->get_published_films(curr_command);
}

vector<FilmInfo> CommandHandler::get_bought_films()
{
	return data->get_active_user()->get_bought_films(curr_command);
}

vector<string> CommandHandler::get_notifs()
{
	return data->get_active_user()->get_notifs();
}

vector<FilmInfo> CommandHandler::search()
{
	return data->search(curr_command);	
}

vector<string> CommandHandler::get_read_notifs()
{
	return data->get_active_user()->get_read_notifs();
}

int CommandHandler::handle_get_money()
{
	if (admin->get_active())
		return admin->get_network_money();
	else
		return data->get_active_user()->get_money();
}

void CommandHandler::logout()
{
	if (data->get_active_user() != NULL)
		data->logout();
	else
		admin->logout();
}
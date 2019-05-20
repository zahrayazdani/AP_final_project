#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <map>
#include <string>

class Data;

class Controller
{
private:
	Data* data;
	void does_user_have_the_film(int film_id);
	void check_get_published_films_optional_datas(std::map<std::string, std::string> command);
	void check_edit_film_optional_datas(std::map<std::string, std::string> command);
	void check_get_bought_films_optional_datas(std::map<std::string, std::string> command);
	void check_validataion_of_email(std::string email);
public:
	Controller(Data* _data);
	void control_signup(std::map<std::string, std::string> command);
	void control_login(std::map<std::string, std::string> command);
	void control_add_film(std::map<std::string, std::string> command);
	void control_reply(std::map<std::string, std::string> command);
	void control_follow(std::map<std::string, std::string> command);
	void control_rate(std::map<std::string, std::string> command);
	void control_comment(std::map<std::string, std::string> command);
	void control_delete_film(std::map<std::string, std::string> command);
	void control_edit_film(std::map<std::string, std::string> command);
	void control_delete_comment(std::map<std::string, std::string> command);
	void control_get_followers(std::map<std::string, std::string> command);
	void control_get_published_films(std::map<std::string, std::string> command);
	void control_get_bought_films(std::map<std::string, std::string> command);
	void control_get_notifs(std::map<std::string, std::string> command);
	void control_get_readen_notifs(std::map<std::string, std::string> command);
	void control_get_money_from_network(std::map<std::string, std::string> command);
	void control_charge_account(std::map<std::string, std::string> command);
};

#endif
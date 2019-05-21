#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <map>

class Publisher;
class Film;
class Comment;

class User
{
protected:
	std::string username;
	std::string email;
	std::string password;
	int age;
	int id;
	bool publisher;
	std::vector<Publisher*> following;
	std::vector<Film*> bought_films;
	int money;
	std::vector<std::string> readen_notifs;
	std::vector<std::string> unread_notifs;
public:
	User(std::map<std::string, std::string> info);
	std::string get_username();
	std::string get_email();
	int get_id();
	bool check_password(std::string pass);
	bool is_publisher();
	Film* find_film(int id);
	void add_new_notif(std::string notif);
	void follow(Publisher* publisher);
};

#endif
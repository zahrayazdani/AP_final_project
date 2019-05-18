#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class Publisher;
class Film;
class Comment;
class Notification;

class User
{
protected:
	std::string username;
	std::string email;
	std::string password;
	int age;
	bool is_publisher;
	std::vector<Publisher*> following;
	std::vector<Film*> bought_films;
	int money;
	std::vector<Notification*> readen_notifs;
	std::vector<Notification*> unread_notifs;
	int id;
public:
	// User();
	std::string get_username();
	std::string get_email();
	int get_id();
	bool check_password(std::string pass);
	bool is_publisher();
	Film* find_film(int id);
};

#endif
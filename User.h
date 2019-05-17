#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

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
	bool is_publisher;
	std::vector<Publisher*> following;
	std::vector<Film*> bought_films;
	int money;
	std::vector<Comment*> readen_notifs;
	std::vector<Comment*> unread_notifs;
	int id;
public:
	// User();
	std::string get_username();
	std::string get_email();
	int get_id();
};

#endif
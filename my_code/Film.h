#ifndef FILM_H
#define FILM_H

#include <string>
#include <vector>
#include <map>
#include "define.h"

class Comment;

class Film
{
private:
	std::string name;
	int year;
	int length;
	int price;
	std::string summary;
	std::string director;
	float rate;
	int id;
	bool deleted;
	std::map<std::string, int> scores;
	std::string publisher_username;
	std::vector<Comment*> comments;
	float calc_rate();
public:
	Film(std::map<std::string, std::string> info);
	// int get_id();
	// std::string get_name();
	// int get_price();
	// float get_rate();
	// int get_year();
	// std::string get_publisher_username();
	// int get_new_comment_id();
	// Comment* find_comment(int id);
	// void delete_comment(int id);
	// void reply_comment(int id, std::string content);
	// void edit_info(std::map<std::string, std::string> info);
	// FilmInfo set_info();
	// bool is_in_range(std::map<std::string, std::string> info);
	// bool is_deleted();
	// std::string add_new_rate(int score, std::string username);
	// std::string add_new_comment(std::string content, std::string writer);
	// void change_delete_stat();
	// std::vector<CommentInfo> get_comments_info();
	// void delete_comments();
};

#endif
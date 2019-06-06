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
	std::vector<Comment*> comments;
	float calc_rate();
public:
	Film(std::map<std::string, std::string> info);
	int get_id();
	std::string get_director();
	int get_price();
	FilmInfo set_info();
	bool is_deleted();
	void add_new_rate(int score, std::string username);
	void add_new_comment(std::string content);
	void change_delete_stat();
	void delete_comments();
	std::vector<Comment*> get_comments();
};

#endif
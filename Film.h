#ifndef FILM_H
#define FILM_H

#include <string>
#include <vector>
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
	std::string publisher_username;
	std::vector<Comment*> comments;
	int id;
	bool is_deleted;
public:
	Film(std::vector<std::string> info);
	int get_id();
	std::string get_name();
	Comment* find_comment(int id);
	void delete_comment(int id);
	void reply_comment(int id, std::string content);
	void edit_info(std::vector<std::string> info);
	FilmInfo set_info();
	bool is_in_range(std::vector<std::string> info);
};

#endif
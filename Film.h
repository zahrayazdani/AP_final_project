#ifndef FILM_H
#define FILM_H

#include <string>
#include <vector>

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
	float Rate;
	std::string publisher_username;
	std::vector<Comment*> comments;
	int id;
public:
	Film();
};

#endif
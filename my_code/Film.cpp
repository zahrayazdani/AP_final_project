#include <iostream>
#include "Film.h"
#include "Comment.h"

using namespace std;

Film::Film(map<string, string> info)
{
	name = info[NAME];
	year = stoi(info[YEAR]);
	length = stoi(info[LENGTH]);
	price = stoi(info[PRICE]);
	summary = info[SUMMARY];
	director = info[DIRECTOR];
	id = stoi(info[FILM_ID]);
	rate = FIRST_RATE;
	deleted = false;
}

int Film::get_id()
{
	return id;
}

string Film::get_director()
{
	return director;
}

FilmInfo Film::set_info()
{
	FilmInfo film_info;
	film_info.id = id;
	film_info.name = name;
	film_info.length = length;
	film_info.price = price;
	film_info.rate = rate;
	film_info.year = year;
	film_info.director = director;
	film_info.summary = summary;
	return film_info;
}

bool Film::is_deleted()
{
	return deleted;
}

void Film::add_new_rate(int score, string username)
{
	scores[username] = score;
	rate = calc_rate();
}

void Film::add_new_comment(string content)
{
	Comment* new_comment = new Comment(content);
	comments.push_back(new_comment);
}

void Film::change_delete_stat()
{
	deleted = true;
}

int Film::get_price()
{
	return price;
}

float Film::calc_rate()
{
	int temp_rate = 0;
	for (map<string, int>::iterator it = scores.begin(); it != scores.end(); ++it)
		temp_rate += it->second;
	float _temp = temp_rate;
	return _temp / scores.size();
}

void Film::delete_comments()
{
	int size = comments.size();
	for (int i = 0; i < size; i++)
		delete comments[i];
}

std::vector<Comment*> Film::get_comments()
{
	return comments;
}
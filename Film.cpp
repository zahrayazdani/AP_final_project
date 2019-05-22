#include <iostream>
#include "Exceptions.h"
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
	publisher_username = info[PUBLISHER];
	rate = FIRST_RATE;
	deleted = false;
	comment_id = FIRST_ID;
}

int Film::get_id()
{
	return id;
}

string Film::get_name()
{
	return name;
}

Comment* Film::find_comment(int id)
{
	for (int i = 0; i < comments.size(); i++)
		if ((comments[i]->get_id() == id) && (!comments[i]->is_deleted()))
			return comments[i];
	return NULL;
}

void Film::delete_comment(int id)
{
	find_comment(id)->change_delete_stat();
}

void Film::reply_comment(int id, string content)
{
	find_comment(id)->add_reply(content);
}

void Film::edit_info(map<string, string> info)
{
	for (map<string, string>::iterator it = info.begin(); it != info.end(); ++it)
	{
		if (it->first == NAME)
			name = it->second;
		else if (it->first == YEAR)
			year = stoi(it->second);
		else if (it->first == LENGTH)
			length = stoi(it->second);
		else if (it->first == SUMMARY)
			summary = it->second;
		else if (it->first == DIRECTOR)
			director = it->second;
	}
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
	return film_info;
}

bool Film::is_in_range(map<string, string> info)
{
	for (map<string, string>::iterator it = info.begin(); it != info.end(); ++it)
	{
		if (it->first == NAME)
		{
			if (it->second != name)
				return false;
		}
		else if (it->first == MINRATE)
		{
			if (rate < stof(it->second))
				return false;
		}
		else if (it->first == MINYEAR)
		{
			if (year < stoi(it->second))
				return false;
		}
		else if (it->first == MAXYEAR)
		{
			if (year > stoi(it->second))
				return false;
		}
		else if (it->first == PRICE)
		{
			if (price != stoi(it->second))
				return false;
		}
		else if (it->first == DIRECTOR)
		{
			if (director != it->second)
				return false;
		}
	}
	return true;
}

bool Film::is_deleted()
{
	return deleted;
}

string Film::add_new_rate(int score)
{
	scores.push_back(score);
	rate = (rate + score) / scores.size();
	return publisher_username;
}

int Film::get_new_comment_id()
{
	comment_id++;
	return comment_id;
}

string Film::add_new_comment(string content, string writer)
{
	Comment* new_comment = new Comment(get_new_comment_id(), writer, content);
	comments.push_back(new_comment);
	return publisher_username;
}

void Film::change_delete_stat()
{
	deleted = true;
}

int Film::get_price()
{
	return price;
}

string Film::get_publisher_username()
{
	return publisher_username;
}

int Film::get_rate()
{
	return rate;
}
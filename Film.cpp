#include <iostream>
#include "Exceptions.h"
#include "Film.h"
#include "Comment.h"

using namespace std;

Film::Film(vector<string> info)
{
	name = info[3];
	year = stoi(info[5]);
	length = stoi(info[7]);
	price = stoi(info[9]);
	summary = info[11];
	director = info[13];
	id = stoi(info[15]);
	publisher_username = info[17];
	rate = FIRST_RATE;
	is_deleted = false;
}

int Film::get_id()
{
	return id;
}

string get_name()
{
	return name;
}

Comment* Film::find_comment(int id)
{
	for (int i = 0; i < comments.size(); i++)
		if (comments[i]->get_id() == id)
			return comments[i];
	return NULL;
}

void Film::delete_comment(int id)
{
	Comment* comment;
	try
	{
		comment = find_comment(id);
	}catch (exception& exception)
	{
		cout << exception.what() << endl;
		return;
	}
	delete comment;
}

void Film::reply_comment(int id, string content)
{
	Comment* comment;
	try
	{
		comment = find_comment(id);	
	}catch (exception& exception)
	{
		cout << exception.what() << endl;
		return;
	}
	comment->add_reply(content);
}

void Film::edit_info(vector<string> info)
{
	for (int i = 4; info.size(); i + 2)
	{
		if (info[i] == NAME_STR)
			name = info[i + 1];
		else if (info[i] == YEAR_STR)
			year = stoi(info[i + 1]);
		else if (info[i] == LENGTH_STR)
			length = stoi(info[i + 1]);
		else if (info[i] == SUMMARY_STR)
			summary = info[i + 1];
		else if (info[i] == DIRECTOR_STR)
			director = info[i + 1];
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

bool Film::is_in_range(std::vector<std::string> info)
{
	for (int i = 2; i < info.size(); i + 2)
	{
		if (info[i] == NAME_STR)
		{
			if (info[i + 1] != name)
				return false;
		}
		else if (info[i] == MINRATE)
		{
			if (rate < stof(info[i + 1]))
				return false;
		}
		else if (info[i] == MINYEAR)
		{
			if (year < stoi(info[i + 1]))
				return false;
		}
		else if (info[i] == MAXYEAR)
		{
			if (year > stoi(info[i + 1]))
				return false;
		}
		else if (info[i] == PRICE)
		{
			if (price != stoi(info[i + 1]))
				return false;
		}
		else if (info[i] == DIRECTOR_STR)
		{
			if (director != info[i + 1])
				return false;
		}
	}
	return true;
}

bool is_deleted()
{
	return is_deleted;
}
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
		if (comments[i]->get_id() == id)
			return comments[i];
	return NULL;
}

// void Film::delete_comment(int id)
// {
// 	Comment* comment;
// 	try
// 	{
// 		comment = find_comment(id);
// 	}catch (exception& exception)
// 	{
// 		cout << exception.what() << endl;
// 		return;
// 	}
// 	delete comment;
// }

void Film::reply_comment(int id, string content)
{
	find_comment(id)->add_reply(content);
}

// void Film::edit_info(vector<string> info)
// {
// 	for (int i = 4; info.size(); i + 2)
// 	{
// 		if (info[i] == NAME)
// 			name = info[i + 1];
// 		else if (info[i] == YEAR)
// 			year = stoi(info[i + 1]);
// 		else if (info[i] == LENGTH)
// 			length = stoi(info[i + 1]);
// 		else if (info[i] == SUMMARY)
// 			summary = info[i + 1];
// 		else if (info[i] == DIRECTOR)
// 			director = info[i + 1];
// 	}
// }

// FilmInfo Film::set_info()
// {
// 	FilmInfo film_info;
// 	film_info.id = id;
// 	film_info.name = name;
// 	film_info.length = length;
// 	film_info.price = price;
// 	film_info.rate = rate;
// 	film_info.year = year;
// 	film_info.director = director;
// 	return film_info;
// }

// bool Film::is_in_range(std::vector<std::string> info)
// {
// 	for (int i = 2; i < info.size(); i + 2)
// 	{
// 		if (info[i] == NAME)
// 		{
// 			if (info[i + 1] != name)
// 				return false;
// 		}
// 		else if (info[i] == MINRATE)
// 		{
// 			if (rate < stof(info[i + 1]))
// 				return false;
// 		}
// 		else if (info[i] == MINYEAR)
// 		{
// 			if (year < stoi(info[i + 1]))
// 				return false;
// 		}
// 		else if (info[i] == MAXYEAR)
// 		{
// 			if (year > stoi(info[i + 1]))
// 				return false;
// 		}
// 		else if (info[i] == PRICE)
// 		{
// 			if (price != stoi(info[i + 1]))
// 				return false;
// 		}
// 		else if (info[i] == DIRECTOR)
// 		{
// 			if (director != info[i + 1])
// 				return false;
// 		}
// 	}
// 	return true;
// }

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
	return commnt_id;
}

string Film::add_new_comment(int content, string writer)
{
	Comment* new_comment = new Comment(get_new_comment_id(), writer, content);
	comment.push_back(new_comment);
	return publisher_username;
}
#ifndef DEFINE_H
#define DEFINE_H

#include <string>

struct FollowersInfo
{
	int user_id;
	std::string username;
	std::string email;
};

struct FilmInfo
{
	int id;
	std::string name;
	int length;
	int price;
	float rate;
	int year;
	std::string director; 
};

#define NOTFOUND "Not Found"
#define BADREQUEST "Bad Request"
#define PERMISSIONDENIED "Permission Denied"
#define FIRST_ID 0
#define FIRST_RATE 0
#define NAME_STR "name"
#define YEAR_STR "year"
#define LENGTH_STR "length"
#define SUMMARY_STR "summary"
#define DIRECTOR_STR "director"
#define USERNAME "username"
#define MINRATE "min_rate"
#define MINYEAR "min_year"
#define MAXYEAR "max_year"
#define PRICE "price"

#endif
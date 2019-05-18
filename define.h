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
#define QUESTION_MARK "?"
#define SPACE ' '
#define POST "POST"
#define PUT "PUT"
#define DELETE "DELETE"
#define GET "GET"
#define READ "read"
#define NOTIFS "notifications"
#define OK "OK"
#define SIGNUP "signup"
#define LOGIN "login"
#define FILMS "films"
#define MONEY "money"
#define REPLIES "replies"
#define FOLLOWERS "followers"
#define BUY "buy"
#define RATE "rate"
#define COMMENTS "comments"
#define PUBLISHED "published"
#define PURCHASED "purchased"
#define READEN_NOTIFS "notificationsread"
#define PASSWORD "password"
#define EMAIL "email"
#define AGE "age"

#endif
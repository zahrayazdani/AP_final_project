#ifndef DEFINE_H
#define DEFINE_H

#include <string>
#include <vector>

enum signupErr {username, pass, ok};

// struct FollowersInfo
// {
// 	int user_id;
// 	std::string username;
// 	std::string email;
// };

// struct FilmInfo
// {
// 	int id;
// 	std::string name;
// 	int length;
// 	int price;
// 	float rate;
// 	int year;
// 	std::string director; 
// 	std::string summary;
// };

// struct  CommentInfo
// {
// 	int id;
// 	std::string content;
// 	std::vector<std::string> replies;
// };

#define NOTFOUND "Not Found"
#define BADREQUEST "Bad Request"
#define PERMISSIONDENIED "Permission Denied"
#define FIRST_ID 0
#define FIRST_RATE 0
#define NAME "name"
#define YEAR "year"
#define LENGTH "length"
#define SUMMARY "summary"
#define DIRECTOR "director"
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
#define READ_NOTIFS "notificationsread"
#define PASSCONFIRM "passwordConfirmation"
#define PASSWORD "password"
#define EMAIL "email"
#define AGE "age"
#define FILM_ID "film_id"
#define COMMENT_ID "comment_id"
#define CONTENT "content"
#define USER_ID "user_id"
#define SCORE "score"
#define MIN_SCORE 1
#define MAX_SCORE 10
#define LIMIT "limit"
#define PUBLISHER "publisher"
#define _TRUE "true"
#define _FALSE "false"
#define AT '@'
#define DOT '.'
#define AMOUNT "amount"
#define ASCII_ZERO '0'
#define ASCII_NINE '9'
#define HIGH_RATE 8
#define LOW_RATE 5
#define EMPTY_STRING ""
#define NUM_OF_RECOMMENDED_FILMS 4
#define PUT_FILMS "put_films"
#define DELETE_FILMS "delete_films"
#define DELETE_COMMENTS "delete_comments"
#define ADMIN "admin"
#define LOGOUT "logout"
#define EMPTY_SESSION_ID ""

#endif
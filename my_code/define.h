#ifndef DEFINE_H
#define DEFINE_H

#include <string>

enum signupErr {username, pass, ok};

struct FilmInfo
{
	int id;
	std::string name;
	int length;
	int price;
	float rate;
	int year;
	std::string director; 
	std::string summary;
};

#define FIRST_ID 0
#define FIRST_RATE 0
#define NAME "name"
#define YEAR "year"
#define LENGTH "length"
#define SUMMARY "summary"
#define DIRECTOR "director"
#define USERNAME "username"
#define PRICE "price"
#define RATE "rate"
#define PASSCONFIRM "passwordConfirmation"
#define PASSWORD "password"
#define EMAIL "email"
#define AGE "age"
#define FILM_ID "film_id"
#define COMMENT_ID "comment_id"
#define CONTENT "content"
#define USER_ID "user_id"
#define SCORE "score"
#define PUBLISHER "publisher"
#define _TRUE "true"
#define _FALSE "false"
#define AMOUNT "amount"
#define NUM_OF_RECOMMENDED_FILMS 4
#define EMPTY_SESSION_ID ""
#define SIZE "size"
#define ID "id"
#define CM "cm"
#define CM_SIZE "cm_size"

#endif
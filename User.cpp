#include "User.h"
#include "Publisher.h"
#include "Film.h"
#include "Comment.h"
#include "Notification.h"

using namespace std;

string User::get_username()
{
	return username;
}

string User::get_email()
{
	return email;
}

int User::get_id()
{
	return id;
}

bool User::check_password(string pass)
{
	return pass == password;
}

bool User::is_publisher()
{
	return is_publisher;
}
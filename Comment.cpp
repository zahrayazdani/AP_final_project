#include "Comment.h"

using namespace std;

int Comment::get_id()
{
	return id;
}

void Comment::add_reply(string reply_message)
{
	reply = reply_message;
}
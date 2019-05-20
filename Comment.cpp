#include "Comment.h"

using namespace std;

int Comment::get_id()
{
	return id;
}

void Comment::add_reply(string reply_message)
{
	replies.push_back(reply_message);
}
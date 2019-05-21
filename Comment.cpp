#include "Comment.h"

using namespace std;

Comment::Comment(int _id, string _writer, string _content)
{
	id = _id;
	writer = _writer;
	content = _content;
}

int Comment::get_id()
{
	return id;
}

void Comment::add_reply(string reply_message)
{
	replies.push_back(reply_message);
}

string Comment::get_writer()
{
	return writer;
}
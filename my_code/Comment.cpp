#include "Comment.h"

using namespace std;

Comment::Comment(string _content)
{
	content = _content;
}

std::string Comment::get_content()
{
	return content;
}
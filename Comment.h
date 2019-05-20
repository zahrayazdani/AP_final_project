#ifndef COMMENT_H
#define COMMENT_H

#include <string>
#include <vector>

class Comment
{
private:
	int id;
	std::string writer;
	std::string content;
	std::vector<std::string> replies;
public:
	// Comment();
	int get_id();
	void add_reply(std::string reply_message);
};

#endif
#ifndef COMMENT_H
#define COMMENT_H

#include <string>
#include <vector>
#include "define.h"

class Comment
{
private:
	int id;
	std::string writer;
	std::string content;
	std::vector<std::string> replies;
	bool deleted;
public:
	Comment(int _id, std::string _writer, std::string _content);
	int get_id();
	std::string get_writer();
	bool is_deleted();
	void add_reply(std::string reply_message);
	void change_delete_stat();
	CommentInfo set_info();
};

#endif
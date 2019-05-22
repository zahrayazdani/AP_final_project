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
	bool deleted;
public:
	Comment(int _id, std::string _writer, std::string _content);
	int get_id();
	void add_reply(std::string reply_message);
	std::string get_writer();
	void change_delete_stat();
	bool is_deleted();
};

#endif
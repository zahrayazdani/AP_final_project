#include <iostream>
#include "CommandHandler.h"
#include "define.h"
#include "Exceptions.h"

using namespace std;

map<string, string> CommandHandler::parse_command(string command)
{
	vector<string> parsed_command;
	size_t first_char = command.find_first_not_of(SPACE);
	size_t first_space_after_word = command.find_first_of(SPACE, first_char);
	string word;

	while(first_char != string::npos)
	{
		word = command.substr(first_char, first_space_after_word - first_char);
		if ((word == READ) && (parsed_command[parsed_command.size() - 1]) == NOTIFS)
			parsed_command[parsed_command.size() - 1] += READ;
		else if (word != QUESTION_MARK)
			parsed_command.push_back(word);
		command.erase(0, first_space_after_word);
		first_char = command.find_first_not_of(SPACE);
		first_space_after_word = command.find_first_of(SPACE, first_char);
	}

	if (parsed_command.size() % 2)
		throw BadRequest();
	return change_vector_to_map(parsed_command);
}

map<string, string> CommandHandler::change_vector_to_map(vector<string> vector)
{
	map<string, string> map;

	for (int i = 0; i < vector.size(); i = i + 2)
		map[vector[i]] = vector[i + 1];

	return map;
}
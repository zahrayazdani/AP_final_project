#include <iostream>
#include "CommandHandler.h"
#include "define.h"

using namespace std;

vector<string> CommandHandler::parse_command(string command)
{
	vector<string> parsed_command;
	size_t first_char = command.find_first_not_of(' ');
	size_t first_space_after_word = command.find_first_of(' ', first_char);
	string word;

	while(first_char != string::npos)
	{
		word = command.substr(first_char, first_space_after_word - first_char);
		if (word != "?")
			parsed_command.push_back(word);
		command.erase(0, first_space_after_word);
		first_char = command.find_first_not_of(' ');
		first_space_after_word = command.find_first_of(' ', first_char);
	}

	return parsed_command;
}
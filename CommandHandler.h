#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <vector>
#include <string>

class CommandHandler
{
public:
	std::vector<std::string> parse_command(std::string command);
};

#endif
#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <vector>
#include <string>
#include <map>

class CommandHandler
{
private:
	std::map<std::string, std::string> change_vector_to_map(std::vector<std::string> vector);
public:
	std::map<std::string, std::string> parse_command(std::string command);
};

#endif
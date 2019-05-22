#ifndef PRINTER_H
#define PRINTER_H

#include <vector>
#include "define.h"

class Printer
{
public:
	void print_success_message();
	void print_followers(std::vector<FollowersInfo> followers);
};

#endif
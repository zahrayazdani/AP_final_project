#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "md5.h"

class Data;

class Admin
{
private:
	const std::string username = ADMIN;
	const std::string password = md5(ADMIN);
	Data* data;
	bool active;
public:
	Admin(Data* _data);
	bool check_password(std::string pass);
	bool get_active();
	int get_network_money();
	void logout();
	void login();
};

#endif
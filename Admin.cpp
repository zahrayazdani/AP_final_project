#include "Admin.h"
#include "Data.h"

using namespace std;

Admin::Admin(Data* _data)
{
	data = _data;
	active = false;
}

bool Admin::check_password(string pass)
{
	return md5(pass) == password;
}

bool Admin::get_active()
{
	return active;
}

int Admin::get_network_money()
{
	return data->get_network_money();
}

void Admin::logout()
{
	active = false;
}
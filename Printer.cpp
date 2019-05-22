#include <iostream>
#include "Printer.h"

using namespace std;

void Printer::print_success_message()
{
	cout << OK << endl;
}

void Printer::print_followers(vector<FollowersInfo> followers)
{
	cout << "List of Followers" << endl;
	cout << "#. User Id | User Username | User Email" << endl;
	for (int i = 0; i < followers.size(); i++)
	{
		cout << i + 1 << ". " << followers[i].user_id << " | " << followers[i].username << " | "
			<< followers[i].email << endl;
	}
}
#include <algorithm>
#include <iostream>
#include "Printer.h"

using namespace std;

void Printer::print_success_message()
{
	cout << OK << endl;
}

void Printer::print_followers(vector<FollowersInfo> followers)
{
	sort(followers.begin(), followers.end(), compare_by_user_id);
	cout << "List of Followers" << endl;
	cout << "#. User Id | User Username | User Email" << endl;
	for (int i = 0; i < followers.size(); i++)
	{
		cout << i + 1 << ". " << followers[i].user_id << " | " << followers[i].username << " | "
			<< followers[i].email << endl;
	}
}

bool Printer::compare_by_user_id(const FollowersInfo& num1, const FollowersInfo& num2)
{
	return num1.user_id < num2.user_id;
}

void Printer::print_films(vector<FilmInfo> films)
{
	sort(films.begin(), films.end(), compare_by_film_id);
	cout << 
		"#. Film Id | Film Name | Film Length | Film price | Rata | Production Year | Film Director"
		<< endl;
	for (int i = 0; i < films.size(); i++)
	{
		cout << i + 1 << ". " << films[i].id << " | " << films[i].name << " | " << films[i].length <<
			" | " << films[i].price << " | " << films[i].rate << " | " << films[i].year << " | " << 
			films[i].director << endl;
	}
}

bool Printer::compare_by_film_id(const FilmInfo& num1, const FilmInfo& num2)
{
	return num1.id < num2.id;
}
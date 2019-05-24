#include <algorithm>
#include <iostream>
#include <iomanip>
#include "Printer.h"
#include "Film.h"

using namespace std;

void Printer::print_success_message()
{
	cout << OK << endl;
}

bool compare_by_user_id(const FollowersInfo& num1, const FollowersInfo& num2)
{
	return num1.user_id < num2.user_id;
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

bool compare_by_film_id(const FilmInfo& num1, const FilmInfo& num2)
{
	return num1.id < num2.id;
}

void Printer::print_films(vector<FilmInfo> films)
{
	sort(films.begin(), films.end(), compare_by_film_id);
	cout << 
		"#. Film Id | Film Name | Film Length | Film price | Rate | Production Year | Film Director"
		<< endl;
	for (int i = 0; i < films.size(); i++)
	{
		cout << i + 1 << ". " << films[i].id << " | " << films[i].name << " | " << films[i].length <<
			" | " << films[i].price << " | " << setprecision(2) << films[i].rate << " | " << films[i].year <<
			" | " << films[i].director << endl;
	}
}

void Printer::print_notifs(vector<string> notifs)
{
	cout << "#. Notification Message" << endl;
	for (int i = notifs.size() - 1; i >= 0; i--)
		cout << notifs.size() - i << ". " << notifs[i] << endl;
}

void Printer::print_read_notifs(vector<string> notifs, int limit)
{
	if (limit > notifs.size())
		limit = notifs.size();
	int size = notifs.size();
	cout << "#. Notification Message" << endl;
	for (int i = size - 1; i >= (size - limit); i--)
		cout << size - i << ". " << notifs[i] << endl;
}

void Printer::print_film_details(Film* film)
{
	FilmInfo info = film->set_info();
	cout << "Details of Film " << info.name << endl;
	cout << "Id = "<< info.id << endl << "Director = " << info.director << endl << "Length = "  << 
		info.length << endl << "Year = " << info.year << endl << "Summary = " <<
		info.summary << endl << "Rate = " << setprecision(2) << info.rate <<
		endl << "Price = " << info.price << endl << endl;

	vector<CommentInfo> comments = film->get_comments_info();
	cout << "Comments" << endl;
	for (int i = 0; i < comments.size(); i++)
	{
		cout << comments[i].id << ". " << comments[i].content << endl;
		for(int j = 0; j < comments[i].replies.size(); j++)
			cout << comments[i].id << "." << j + 1 << ". " << comments[i].replies[j] << endl;
	}
	cout << endl;
}

void Printer::print_recommend_films(vector<FilmInfo> recommends)
{
	cout << "Recommendation Film" << endl <<
		"#. Film Id | Film Name | Film Length | Film Director" << endl;
	for (int i = 0; i < recommends.size(); i++)
		cout << i + 1 << ". " << recommends[i].id << " | " << recommends[i].name << " | " <<
			recommends[i].length << " | " << recommends[i].director << endl;
}

void Printer::print_amount_of_money(int money)
{
	cout << money << endl;
}
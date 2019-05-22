#include <algorithm>
#include <iostream>
#include "Printer.h"
#include "Film.h"

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

void Printer::print_notifs(vector<string> notifs)
{
	cout << "#. Notification Message" << endl;
	for (int i = notifs.size() - 1; i >= 0; i--)
		cout << notifs.size() - i << ". " << notifs[i] << endl;
}

void Printer::print_readen_notifs(vector<string> notifs, int limit)
{
	cout << "#. Notification Message" << endl;
	for (int i = notifs.size() - 1; i >= notifs.size() - limit; i--)
		cout << notifs.size() - i << ". " << notifs[i] << endl;
}

void Printer::print_film_details(Film* film)
{
	FilmInfo info = film->set_info();
	cout << "Details of Film " << info.name << endl;
	cout << "Id = "<< info.id << endl << "Director = " << info.director << endl << "Year = " <<
		info.year << endl << "Summary = " << info.summary << endl << "Rate = " << info.rate <<
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
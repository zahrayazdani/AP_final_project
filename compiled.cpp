#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include "utils/utilities.hpp"
using namespace std;
int main(int argc, char const *argv[])
{
std::map<std::string, std::string> context;
readMapFromFile(".template/map.txt", &context);
string __unparsedTemplate__ = readFile(".template/local3.html");

string __variable0;
__variable0 = __unparsedTemplate__.substr(0, 223);
cout << __variable0;
		cout << "Name : " << context["name"] << endl;
		cout << "Length : " << context["length"] << endl;
		cout << "Price : " << context["price"] << endl;
		cout << "Rate : " << context["rate"] << endl;
		cout << "Year : " << context["year"] << endl;
		cout << "Director : " << context["director"] << endl;
		cout << "Summary : " << context["summary"] << endl;
		cout << "Comments:";
		int num_of_cms = stoi(context["cm_size"]);
		string cm_num;
		for (int i = 0; i < num_of_cms; i++)
		{
			cm_num = to_string(i);
			cout << context["cm" + cm_num] << " ";
		}
	
string __variable1;
__variable1 = __unparsedTemplate__.substr(785, 86);
cout << __variable1; cout << context["id"]; 
string __variable2;
__variable2 = __unparsedTemplate__.substr(899, 61);
cout << __variable2;
		int num_of_films = stoi(context["size"]);
		string film_num;
		cout << "Recommended for you :" << endl;
		cout << "Name  " << "length  " << "director" << endl; 
		for (int i = 0; i < num_of_films; i++)
		{
			film_num = to_string(i);
			cout << context["name" + film_num] << " ";
			cout << context["length" + film_num] << " ";
			cout << context["director" + film_num] << " ";
	
string __variable3;
__variable3 = __unparsedTemplate__.substr(1346, 87);
cout << __variable3; cout << context["id" + film_num]; 
string __variable4;
__variable4 = __unparsedTemplate__.substr(1472, 153);
cout << __variable4; cout << context["id" + film_num]; 
string __variable5;
__variable5 = __unparsedTemplate__.substr(1664, 65);
cout << __variable5;
		}
	
string __variable6;
__variable6 = __unparsedTemplate__.substr(1739, 19);
cout << __variable6;
return 0;
}

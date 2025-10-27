#include <iostream>
#include<string>
using namespace std;

struct stUser
{
	string first_name;
	string last_name;
};
stUser reader()
{
	stUser user;
	cout<<"your first name :"<<endl;
	getline(cin, user.first_name);
	cout << "your last name :" << endl;
	getline(cin , user.last_name);
	return user;
}
string fullname(stUser user)
{
	string fullname;
	fullname = user.first_name + " " + user.last_name;
	return fullname;
}
void printer(string fullname)
{
	cout << "your name is " << fullname <<endl;
	
}
int main()
{
	printer(fullname(reader()));
}



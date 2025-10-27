#include <iostream>
#include<string>
using namespace std;
string reader()
{
	string name;
	cout << "Your name : " << endl;
	getline(cin,name);
	return name;
}
void printer(string name)
{
	cout << "Your name is :" << name;
}
int main()
{
	printer(reader());
	return 0;
}
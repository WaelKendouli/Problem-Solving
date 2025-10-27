#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string str;
	cout << "Enter Your String ? :" << endl;
	getline(cin, str);
	return str;
}
string TrimLeft(string str)
{
	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			return str.substr(i, str.length() - 1);
		}
	}
	return "";
}
string TrimRigth(string str)
{
	for (short i = str.length(); i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			return str.substr(0, i+1);
		}
	}
	return "";
}
string Trim(string str)
{

	return TrimLeft(TrimRigth(str));
}
int main()
{
	string str = ReadString();
	cout << "String : \n" << str;
	cout << "\nTrim left : \n" << TrimLeft(str);
	cout << "\nTrim rigth : \n" << TrimRigth(str);
	cout << "\nTrim : \n" << Trim(str);

	return 0;
}

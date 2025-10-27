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
string UpperCaseFirstLetterOfEachWord(string str)
{
	
	for (short i = 0; i < str.length(); i++)
	{
			str[i] = toupper(str[i]);
	}
	return str;
}
string LowerCaseFirstLetterOfEachWord(string str)
{

	for (short i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}
int main()
{
	string str = ReadString();
	cout << "String After lower : \n";
	str = LowerCaseFirstLetterOfEachWord(str);
	cout << str<<endl;
	cout << "String After Upper : \n";
	str = UpperCaseFirstLetterOfEachWord(str);
	cout << str<<endl;
	return 0;
}

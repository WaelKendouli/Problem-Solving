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
	bool isFirstLetter = true;
	
	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && isFirstLetter)
		{
			str[i] = toupper(str[i]);
		
		}
		
		isFirstLetter = (str[i] == ' ' ? true : false);
		
	}
	return str;
}
int main()
{
	string str = ReadString();
	str = UpperCaseFirstLetterOfEachWord(str);
	cout << str;
	return 0;
}


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
void PrintFirstLetterOfEachWord(string str)
{
	bool isFirstLetter = true;
	cout << "first letter of string :\n";
	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] != ' '&&isFirstLetter)
		{
			cout << str[i] << endl; 
			isFirstLetter = false;
		}
		isFirstLetter = (str[i] == ' ' ? true : false);
	}
}
int main()
{
	PrintFirstLetterOfEachWord(ReadString());
	return 0;
}



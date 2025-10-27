#include <iostream>
#include<string>

using namespace std;


string RemovePunctuationsFromWord(string str)
{
	string S = "";
	for (short i = 0; i < str.length(); i++)
	{
		if (!ispunct(str[i]))
		{
			S += str[i];
		}
	}
	return S;
}




int main()
{
	string str = "Welcom: to Algeria , Algeria is a beautiful contury ; it's amazing.\n\n";
	cout << "\n\nOriginal  string : \n\n";
	cout << str;
	
	cout << "\n\n  string after removing Punctuations : \n\n";
	cout << RemovePunctuationsFromWord(str);
}



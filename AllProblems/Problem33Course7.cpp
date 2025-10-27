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

bool CheckIfVowel(char ch)
{

	ch = tolower(ch);

	return ((ch == 'a') || (ch == 'i') || (ch == 'e') || (ch == 'u') || (ch == 'o'));

}
short int CountVowelsNumber(string str)
{
	short int Counter = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (CheckIfVowel(str[i]))
		{
			Counter++;
		}
	}
	return Counter;
}
int main()
{
	cout << "Number of vowels is : " << CountVowelsNumber(ReadString())<<endl;

}



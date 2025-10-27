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
void PrintVowelsInString(string str)
{
	cout << " Vowels in String are : ";
	for (short i = 0; i < str.length(); i++)
	{
		if (CheckIfVowel(str[i]))
		{
			cout << str[i] << "\t";
		}
	}

}
int main()
{
	
		PrintVowelsInString(ReadString());

}

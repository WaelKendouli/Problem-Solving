

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
char InvertCharecter(char Charecter)
{
	return isupper(Charecter) ? tolower(Charecter) : toupper(Charecter);
}
string InvertEachLetterInString(string str)
{
	
	for (short i = 0; i <= str.length(); i++)
	{
	str[i]	=InvertCharecter(str[i]);
	}
	return str;
}
int main()
{
	string str = ReadString();
	str = InvertEachLetterInString(str);
	cout << str;
	return 0;
}



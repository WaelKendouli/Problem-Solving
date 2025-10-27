#include <iostream>
#include <string>
using namespace std;
enum enSmallOrCapital { Small = 0 , SmallandCapital = 1};

string ReadString()
{
	string str;
	cout << "Enter Your String ? :" << endl;
	getline(cin, str);
	return str;
}
char ReadChar()
{
	char Ch;
	cout << "Enter Your Charecter  ? :" << endl;
	cin >> Ch;
	return Ch;
}
short int CountSepiceficLetter(string str, char Charecter , bool MatchCase=false )
{
	short int Counter = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if(MatchCase)
		{
			if (str[i] == Charecter)
				Counter++;
			else
			{
				if (tolower(str[i]) == tolower(Charecter))
					Counter++;
			}
		}
	}
	return Counter;
}
void PrintResults(char Charecter, short int Counter)
{
	cout << "Letter '" << Charecter << "'count = " << Counter << endl;
}
int main()
{
	string str = ReadString();
	char Charecter = ReadChar();
	short int Counter = CountSepiceficLetter(str, Charecter);
	PrintResults(Charecter, Counter);
	cout << "Letter \'" << Charecter<<"'\ Or \'"<< char(toupper(Charecter)) << "'\count = " << Counter << endl;
		
}

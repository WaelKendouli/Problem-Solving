

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
char ReadChar()
{
	char Ch;
	cout << "Enter Your Charecter  ? :" << endl;
	cin >> Ch;
	return Ch;
}
short int CountSepiceficLetter(string str , char Charecter)
{
	short int Counter = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (str[i]==Charecter)
			Counter++;
	
	}
	return Counter;
}
void PrintResults( char Charecter, short int Counter)
{
	cout << "Letter '" << Charecter << "'count = " << Counter << endl;
}
int main()
{
	string str = ReadString();
	char Charecter = ReadChar();
	short int Counter = CountSepiceficLetter(str, Charecter);
	PrintResults(Charecter, Counter);

}


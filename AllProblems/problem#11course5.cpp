#include <iostream>
using namespace std;

int ReadNumber(string str)
{
	int Number;
	do
	{
		cout << str << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}
int ReversedNumber(int Number)
{
	int remain=0, Number2=0;
	while (Number > 0)
	{
		remain = Number % 10;
		Number = Number / 10;
		Number2 = Number2 * 10 + remain;

	}
	return Number2;
}
bool checkifPalindrom( int Number)
{

	return Number = ReversedNumber(Number);
}
int main()
{
	if (checkifPalindrom(ReadNumber("Number") == true))
		cout << "Palindrom\n";
	else
		cout << "Not Palindrom\n";
	
}



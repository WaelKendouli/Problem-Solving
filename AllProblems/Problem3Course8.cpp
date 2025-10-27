

#include <iostream>
#include <string>

using namespace std;

bool LeapYearOrNot(int Year)
{
	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}
string Result(bool Lyear ,int year)
{
	if (Lyear==true)
	{
		return "Yes , " + to_string(year) + " is a leap year \n";
	}
	else
	{
		return "No , "+ to_string(year) + " is Not leap year \n";

	}
}
int ReadNumber()
{
	int Number;
	cout << "Enter a year\n";
	cin >> Number;
	return Number;
}
int main()
{
	int year = ReadNumber();
	bool isLeapYear = LeapYearOrNot(year);
	cout << Result(isLeapYear, year);
}



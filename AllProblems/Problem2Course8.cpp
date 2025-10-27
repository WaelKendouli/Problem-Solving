

#include <iostream>
#include <string>

using namespace std;

string LeapYearOrNot(int Year)
{
	if (Year%400==0)
	{
		return"yes , "+ to_string(Year) + " is a Leap year \n";
	}
	else
	{
		if (Year % 4 == 0 &&  Year % 100 != 0)
		{
			return"yes , " + to_string(Year) + " is a Leap year \n";

		}
	}
	return "No , " + to_string(Year) + " is NOT a Leap year \n";
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
	cout << LeapYearOrNot(year);
}
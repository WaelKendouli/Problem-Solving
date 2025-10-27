#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;
	cout << "Enter a year\n";
	cin >> Number;
	return Number;
}
bool LeapYearOrNot(int Year)
{
	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}
int NumberOfDaysInYear(int year)
{
	return LeapYearOrNot(year) ? 366 : 365;
}
int NumberofHoursInYear(int year)
{
	return (NumberOfDaysInYear(year) * 24);
}
int NumberofMinutesInYear(int year)
{
	return (NumberofHoursInYear(year) * 60);
}
int NumberofSecondsInYear(int year)
{
	return (NumberofMinutesInYear(year) * 60);
}

void ShowResults(int year)
{
	cout << " Number of Days in Year [" << year << "] is " << NumberOfDaysInYear(year) << endl;
	cout << " Number of Hours in Year [" << year << "] is " << NumberofHoursInYear(year) << endl;
	cout << " Number of Minutes in Year [" << year << "] is " << NumberofMinutesInYear(year) << endl;
	cout << " Number of Seconds in Year [" << year << "] is " << NumberofSecondsInYear(year) << endl;

}
int main()
{
	int year = ReadNumber();
	ShowResults(year);
}



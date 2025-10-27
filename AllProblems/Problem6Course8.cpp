#include <iostream>
using namespace std;

int ReadNumber(string str)
{
	int Number;
	cout << "Enter a " << str << "\n";
	cin >> Number;
	return Number;
}

bool LeapYearOrNot(int Year)
{
	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

int DaysInMounthTwo(int year, short Mounth)
{
	return LeapYearOrNot(year) ? 29 : 28;
}
int DaysInMounth(int year, short Mounth)
{
	short ArrofDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (Mounth < 1 || Mounth > 12)
	{
		return 0;
	}
	return Mounth == 2 ? DaysInMounthTwo(year, Mounth) : (Mounth == ArrofDays[Mounth - 1] ? 31 : 30);
}
int NumberofHoursInMounth(int year, short Mounth)
{
	return (DaysInMounth(year, Mounth) * 24);
}
int NumberofMinutesInMounth(int year, short Mounth)
{
	return (NumberofHoursInMounth(year, Mounth) * 60);
}
int NumberofSecondsInMounth(int year, short Mounth)
{
	return (NumberofMinutesInMounth(year, Mounth) * 60);
}

void ShowResults(int year, short Mounth)
{
	cout << " Number of Days in Mounth [" << Mounth << "] is " << DaysInMounth(year, Mounth) << endl;
	cout << " Number of Hours in Mounth [" << Mounth << "] is " << NumberofHoursInMounth(year, Mounth) << endl;
	cout << " Number of Minutes in Mounth [" << Mounth << "] is " << NumberofMinutesInMounth(year, Mounth) << endl;
	cout << " Number of Seconds in Mounth [" << Mounth << "] is " << NumberofSecondsInMounth(year, Mounth) << endl;

}
int main()
{
	int year = ReadNumber("Year");
	int Mounth = ReadNumber("Mounth");
	ShowResults(year, Mounth);
	system("pause>0");
}

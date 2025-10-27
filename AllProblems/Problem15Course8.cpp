#include <iostream>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};


short ReadNumber(string str)
{
	short Number;
	cout << " Please Enter a " << str << " ?\n";
	cin >> Number;
	return Number;
}

bool LeapYearOrNot(int Year)
{
	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}
short DaysInMounthTwo(int year, short Mounth)
{
	return LeapYearOrNot(year) ? 29 : 28;
}
short DaysInMounth(int year, short Mounth)
{
	short ArrofDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (Mounth < 1 || Mounth > 12)
	{
		return 0;
	}
	return Mounth == 2 ? DaysInMounthTwo(year, Mounth) : (Mounth == ArrofDays[Mounth - 1] ? 31 : 30);
}


stDate ReadDate()
{
	stDate Date;
	Date.Day = ReadNumber("Day");
	Date.Month = ReadNumber("Mounth");
	Date.Year = ReadNumber("year");

	return Date;
}
bool IsLastDayInMounth(stDate Date,short LastDayInMounth)
{
	return (Date.Day == LastDayInMounth) ? true : false;
}
bool IsLastMounthInYear(stDate Date)
{
	return (Date.Month == 12) ? true : false;
}

string Result(string str1, string str2, bool isLast)
{
	return ((isLast == true) ? "Yes " + str1 + " is the last " + str1 + " in " + str2 : " No " + str1 + " is NOT the last " + str1 + " in " + str2);
}
int main()
{
	stDate Date;
	Date = ReadDate();
	short LastDayInMounth = DaysInMounth(Date.Year, Date.Month);
	cout << Result("Day", "Month", IsLastDayInMounth(Date, LastDayInMounth));
	cout << "\n\n";
	cout << Result("Month", "Year", IsLastMounthInYear(Date));

	system("pause>0");
}



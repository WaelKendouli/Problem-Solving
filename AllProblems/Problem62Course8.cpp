

#include <iostream>
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

short ReadNumber(string str)
{
	short Number;
	cout << " Please Enter a " << str << " ?\n";
	cin >> Number;
	return Number;
}
stDate ReadDate()
{
	stDate Date;
	Date.Day = ReadNumber("Day");
	Date.Month = ReadNumber("Mounth");
	Date.Year = ReadNumber("year");

	return Date;
}

bool CompareDates(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

	if (Mounth < 1 || Mounth > 12)
	{
		return 0;
	}
	short ArrofDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Mounth == 2) ? (LeapYearOrNot(year) ? 29 : 28) :
		ArrofDays[Mounth - 1];
}

bool IsDateValid(stDate Date)
{

	return (Date.Month<1||Date.Month > 12 ? false : (Date.Day<1 || Date.Day > DaysInMounth(Date.Year, Date.Month) ? false : true));
}

bool IsDateValid2(stDate Date)
{
	if (Date.Day < 1 || Date.Day > 31)
		return false;
	if (Date.Month < 1 || Date.Month > 12)
		return false;

	if (Date.Month==2)
	{
		if (LeapYearOrNot(Date.Year))
		{
			if (Date.Day>29)
			{
				return false;
			}
		}
		else
		{
			if (Date.Day > 28)
			{
				return false;
			}
		}

	}

	short LastDayInMonth = DaysInMounth(Date.Year, Date.Month);

	if ( Date.Day> LastDayInMonth)
	{
		return false; 
	}
	return true;
}
int main()
{
	stDate Date = ReadDate();

	if (IsDateValid2(Date))
		cout << "Yes,Date is a valid date ";
	else
		cout << "No,Date is NOT a valid date ";

	system("pause>0");
}



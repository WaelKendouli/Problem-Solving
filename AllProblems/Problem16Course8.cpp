#include <iostream>
using namespace std;

struct stDate
{
	short day;
	short month;
	short year;
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
	
	if (Mounth < 1 || Mounth > 12)
	{
		return 0;
	}
	short ArrofDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Mounth == 2) ? (LeapYearOrNot(year) ? 29 : 28) :
		ArrofDays[Mounth - 1];
}

stDate ReadDate()
{
	stDate Date;
	Date.day = ReadNumber("Day");
	Date.month = ReadNumber("Mounth");
	Date.year = ReadNumber("year");

	return Date;
}
bool IsLastDayInMounth(stDate Date)
{
	return (Date.day == DaysInMounth(Date.year, Date.month));
}
bool IsLastMounthInYear(stDate Date)
{
	return (Date.month == 12) ? true : false;
}

stDate UpdateDate(stDate Date)
{
	
	if (IsLastDayInMounth(Date)==true)
	{
		if (IsLastMounthInYear(Date) == true)
		{
			Date.year++;
			Date.month = 1;
			Date.day = 1;
		}
		else
		{
			Date.day=1;
			Date.month++;
		}
	}
	
	else
	{
		Date.day++;
	}
	
		
	
	return Date;
}

int main()
{
	stDate Date;
	Date = ReadDate();
	 Date=UpdateDate(Date);
	cout << "Date after adding one day : " << Date.day << "/" << Date.month << "/" << Date.year<<endl;
	system("pause");
}



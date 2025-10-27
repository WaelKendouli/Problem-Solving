#include <iostream>

using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
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
stPeriod ReadPeriod()
{
	stPeriod Period;
	cout << "Start date :\n\n";
	Period.StartDate = ReadDate();
	cout << "\nEnd date :\n";
	Period.EndDate = ReadDate();

	return Period;
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
stDate IncreaseDateByOneDay(stDate Date)
{
	if (Date.Day==DaysInMounth(Date.Year,Date.Month))
	{
		if (Date.Month==12)
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}
int GetDiffrenceBetweenDates(stDate Date1, stDate Date2, bool includeEndDAY = false)
{
	int days = 0;
	while (CompareDates(Date1, Date2))
	{
		days++;
		Date1 = IncreaseDateByOneDay(Date1);

	}
	return includeEndDAY == true ? (days+1) : days;
}

int PeriodLengthInDays(stPeriod Period, bool includeEndDAY=false)
{
	return GetDiffrenceBetweenDates(Period.StartDate, Period.EndDate,includeEndDAY);
}
int main()
{
	stPeriod Period;
	cout << "Period 1 : \n\n";
	Period = ReadPeriod();
	cout << "\n\n";

	cout << "Period Length : "<<PeriodLengthInDays(Period)<<"  "<<endl;
	cout << "Period Length (Including End Date) is : " << PeriodLengthInDays(Period,true) << endl;

	system("pause>0");
}



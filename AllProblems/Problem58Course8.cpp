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

enum enDateStatus { Before = -1, Equal = 0, After = 1 };

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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month ==
		Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false)
		: false;
}

bool isDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enDateStatus CompareDates(stDate Date1, stDate Date2)
{
	if (isDate1AfterDate2(Date1, Date2) == true)
	{
		return enDateStatus::After;
	}
	if (IsDate1EqualDate2(Date1, Date2) == true)
	{
		return enDateStatus::Equal;
	}

	return enDateStatus::Before;
}

bool isPeriodsAreOverlaped(stPeriod Period1, stPeriod Period2)
{
	if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateStatus::Before
		|| CompareDates(Period2.StartDate, Period1.EndDate) == enDateStatus::After)
	{
		return false;
	}
	else
		return true;
}

int main()
{
	stPeriod Period1, Period2;
	cout << "\nPeriod 1 :\n";
	Period1 = ReadPeriod();
	cout << "\nPeriod 2 :\n";
	Period2 = ReadPeriod();

	if (isPeriodsAreOverlaped(Period1,Period2)==true)
	{
		cout << "Yes, Periods overlap\n\n";
	}
	else
		cout << "No, Periods NOT overlap\n\n";

    system("pause>0");
}



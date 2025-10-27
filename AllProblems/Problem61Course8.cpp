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
	if (Date.Day == DaysInMounth(Date.Year, Date.Month))
	{
		if (Date.Month == 12)
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
	return includeEndDAY == true ? (days + 1) : days;
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

enDateStatus CompareDatesInGeneral(stDate Date1, stDate Date2)
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
	if (CompareDatesInGeneral(Period2.StartDate, Period1.StartDate) == enDateStatus::Before
		|| CompareDatesInGeneral(Period2.EndDate, Period1.EndDate) == enDateStatus::After)
	{
		return false;
	}
	else
		return true;
}

bool IsDateInRange(stPeriod Period1, stDate Date)
{
	return !(CompareDatesInGeneral(Date, Period1.StartDate) == enDateStatus::Before
		|| CompareDatesInGeneral(Date, Period1.EndDate) == enDateStatus::After);
}
int PeriodLengthInDays(stPeriod Period, bool includeEndDAY = false)
{
	return GetDiffrenceBetweenDates(Period.StartDate, Period.EndDate, includeEndDAY);
}
int CountOverLapDates(stPeriod Period1, stPeriod Period2)
{
	int OverLapDays = 0;
	int Period1Length = PeriodLengthInDays(Period1, true);
	int Period2Length = PeriodLengthInDays(Period2, true);

	if (isPeriodsAreOverlaped(Period1,Period2))
	{
		return 0;
	}
		if (Period1Length<Period2Length)
		{
			while (!IsDate1EqualDate2(Period1.StartDate, Period1.EndDate))
			{
				if (IsDateInRange(Period2, Period1.StartDate) == true)
				{
					OverLapDays++;
				}
				Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
			}
		}
		else
		{
			while (IsDate1EqualDate2(Period2.StartDate, Period2.EndDate) == false)
			{
				if (IsDateInRange(Period1, Period2.StartDate) == true)
				{
					OverLapDays++;
				}
				Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
			}
		}
	
	return OverLapDays;
}

	

int main()
{
	stPeriod Period1, Period2;
	cout << "Period 1 : \n\n";
	Period1 = ReadPeriod();
	cout << "\n\n";

	cout << "Period 2 : \n\n";
	Period2 = ReadPeriod();
	cout << "\n\n";

	cout << " OverLap Count is : " << CountOverLapDates(Period1, Period2) << endl;

	system("pause>0");
}

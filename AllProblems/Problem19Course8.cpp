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

bool CompareDates(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}



stDate ReadDate()
{
	stDate Date;
	Date.Day = ReadNumber("Day");
	Date.Month = ReadNumber("Mounth");
	Date.Year = ReadNumber("year");

	return Date;
}

short PastDaysInYear(int year, short Mounth, short Day)
{
	short SumOfDaysInPastMounths = 0;
	for (short PastMounth = 1; PastMounth <= Mounth - 1; PastMounth++)
	{
		SumOfDaysInPastMounths = SumOfDaysInPastMounths + DaysInMounth(year, PastMounth);
	}
	SumOfDaysInPastMounths += Day;
	return SumOfDaysInPastMounths;
}
bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == PastDaysInYear(Date.Month, Date.Year, Date.Day));
}
bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}
stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
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
int GetDiffrenceBetweenDates(stDate& Date1, stDate& Date2, bool includeEndDAY = false , bool FirstComparation=false)
{
	int days = 0;
	while (CompareDates(Date1, Date2)==true|| CompareDates(Date1, Date2) == false)
	{
		days++;
		Date1 = IncreaseDateByOneDay(Date1);

	}
	if (FirstComparation==false)
	{
		return (days * -1);
	}
	return includeEndDAY == true ? days++ : days;
}
int main()
{
	stDate Date1, Date2;
	
		Date1 = ReadDate();
		cout << "\n\n";
		Date2 = ReadDate();
		bool FirstCompare;
		FirstCompare = CompareDates(Date1, Date2);

	cout << "\nDiffrence (including end day) :" << GetDiffrenceBetweenDates(Date1, Date2,true,FirstCompare) << " Day(s)\n\n";

	system("pause>0");
}

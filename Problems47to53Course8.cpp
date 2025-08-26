#pragma warning(disable:4996)
#include <iostream>
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};



stDate GetSystemDate()
{
	stDate Date;
	time_t t = time(0);
	tm* now = localtime(&t);
	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;
	return Date;
}


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
short PastDaysInYear(stDate Date)
{
	short SumOfDaysInPastMounths = 0;
	for (short PastMounth = 1; PastMounth <= Date.Month - 1; PastMounth++)
	{
		SumOfDaysInPastMounths = SumOfDaysInPastMounths + DaysInMounth(Date.Year, PastMounth);
	}
	SumOfDaysInPastMounths += Date.Day;
	return SumOfDaysInPastMounths;
}
bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == PastDaysInYear(Date));
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

int GetDiffrenceBetweenDates(stDate& Date1, stDate& Date2, bool includeEndDAY = false)
{
	int days = 0;
	while (CompareDates(Date1, Date2))
	{
		days++;
		Date1 = IncreaseDateByOneDay(Date1);

	}
	return includeEndDAY == true ? days++ : days;
}


void ShowDate(stDate Date)
{
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

string ReturnDate(short DayOfWeek)
{
	string ArrDate[] = { "Sun","Mon","Tue","Wed","Thur","Fri","Sat" };
	return ArrDate[DayOfWeek];
}

short DayInGregorianCalender(short Day, short Month,short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;


	return  (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}

short DayInGregorianCalender(stDate Date)
{
	return DayInGregorianCalender(Date.Day, Date.Month, Date.Year);
}
bool isEndOfWeekDay(stDate date)
{
	return(DayInGregorianCalender(date) == 6);
}
bool isWeekendDate(stDate date)
{
	short testDate = DayInGregorianCalender(date);
	return (testDate == 5 || testDate == 6);
}

bool IsBussinessDay(stDate Date)
{
	return !isWeekendDate(Date);
}
string ShowifendOfWeek(bool testofdate)
{
	if (testofdate == true)
		return "yes,Saturday is end of week  \n\n";
	else
		return "No,its NOT end of week \n\n";

}

string ShowifWeekend(bool testofdate)
{
	if (testofdate == true)
		return "yes, a week end \n\n";
	else
		return "No,its NOT a week end \n\n";

}

string ShowifBussinesDay(bool testofweekend)
{
	if (testofweekend == false)
		return "No,its NOT a Bussines day\n\n";
	else
		return "yes,its a Bussines day\n\n";

}

short DaysUntilEndOfWeek(stDate Date)
{
	return(6 - DayInGregorianCalender(Date));
}

short DaysUntilEndOfMonth(stDate Date)
{
	stDate EndofMonth;
	EndofMonth.Day = DaysInMounth(Date.Year, Date.Month);
	EndofMonth.Month = Date.Month;
	EndofMonth.Year = Date.Year;
	return GetDiffrenceBetweenDates(Date, EndofMonth, true);
}

short DaysUntilEndOfTheYear(stDate Date)
{
	stDate EndofMonth;
	EndofMonth.Day = 31;
	EndofMonth.Month = 12;
	EndofMonth.Year = Date.Year;
	return GetDiffrenceBetweenDates(Date, EndofMonth, true);
}
int main()
{
	stDate Date;
	Date = GetSystemDate();
	

	cout << "Today is : " << ReturnDate(DayInGregorianCalender(Date))<<" ";
	ShowDate(Date);
	cout << "Is end of week ?" << endl;
	cout << ShowifendOfWeek(isEndOfWeekDay(Date));
	cout << "\n\n";

	cout << "Is it weekend ?" << endl;
	cout << ShowifWeekend(isWeekendDate(Date));
	cout << "\n\n";

	cout << "Is it Bussines day ?" << endl;
	cout << ShowifBussinesDay(IsBussinessDay(Date));
	cout << "\n\n";

	cout << "Days Until end of the week ";
	cout << DaysUntilEndOfWeek(Date)<<endl;

	cout << "Days Until end of the month ";
	cout << DaysUntilEndOfMonth(Date) << endl;

	cout << "Days Until end of the year ";
	cout << DaysUntilEndOfTheYear(Date) << endl;

   system("pause>0");
}



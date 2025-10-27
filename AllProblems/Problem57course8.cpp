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




void ShowDate(stDate Date)
{
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

string ReturnDate(short DayOfWeek)
{
	string ArrDate[] = { "Sun","Mon","Tue","Wed","Thur","Fri","Sat" };
	return ArrDate[DayOfWeek];
}

short DayInGregorianCalender(short Day, short Month, short Year)
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
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
short GetNumberOfWeekendDays(stDate Date1 , stDate Date2)
{
	short NumberOfWeekends=0;
	
	while (IsDate1BeforeDate2(Date1,Date2))
	{
		if (isWeekendDate(Date1) == true);
		{
			NumberOfWeekends++;
		}
		Date1 = IncreaseDateByOneDay(Date1);
	}

	

		
	
	return NumberOfWeekends;
}


int main()
{
	stDate Date1, Date2;
	cout << "Vacation Starts : \n";
	Date1 = ReadDate();
	cout << "\n\n";
	cout << "Vacation ends : \n";
	Date2 = ReadDate();
	cout << "\n\n";

	cout << "Vacation from : " << ReturnDate(DayInGregorianCalender(Date1))<<" ";
	ShowDate(Date1);
	cout << "Vacation ends : " << ReturnDate(DayInGregorianCalender(Date2))<<" ";
	ShowDate(Date2);
	cout << "\n\n";

	cout << " Actual Vaction Days " << GetNumberOfWeekendDays(Date1,Date2);
    system("pause>0");
}


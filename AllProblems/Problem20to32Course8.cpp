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
	short SumOfDaysInPastMonths = 0;
	for (short i = 1; i <= Mounth - 1; i++)
	{
		SumOfDaysInPastMonths = SumOfDaysInPastMonths + DaysInMounth(year, i);
	}
	SumOfDaysInPastMonths += Day;
	return SumOfDaysInPastMonths;
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
stDate IncreaseDateByXDays(stDate Date , short Number)
{
	for (short i = 0; i < Number; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	
	return Date;
}
stDate IncreaseDateByOneWeek(stDate Date)
{
	return IncreaseDateByXDays(Date, 7);

}
stDate IncreaseDateByXWeeks(stDate Date,short Number)
{
	
	for (short i = 0; i < Number; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
	return IncreaseDateByXDays(Date, DaysInMounth(Date.Year,Date.Month+1));

}
stDate IncreaseDateByXMonth(stDate Date , short Xmonths)
{

	for (short i = 0; i < Xmonths ; i++)
	{
		
		Date= IncreaseDateByOneMonth(Date);
		
	}
	return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
	Date.Year++;
	return Date;
}
stDate IncreaseDateByXYear(stDate Date, short Xyear)
{

	for (short i = 0; i < Xyear; i++)
	{

		Date = IncreaseDateByOneYear(Date);

	}
	return Date;
}

stDate IncreaseDateByXYearFaster(stDate Date, short Xyear)
{
	Date.Year += Xyear;

	return Date;
}
stDate IncreaseDateByOneDecade(stDate Date)
{
	
	return IncreaseDateByXYear(Date, 10);
}
stDate IncreaseDateByXDecade(stDate Date, short XDecade)
{

	for (short i = 0; i < XDecade; i++)
	{

		Date = IncreaseDateByOneDecade(Date);

	}
	return Date;
}

stDate IncreaseDateByXDecadeFaster(stDate Date, short XDecade)
{

		Date.Year += XDecade * 10;

	return Date;
}

stDate IncreaseDateByOneCentery(stDate Date)
{
	Date.Year += 100;
	return Date;
}
stDate IncreaseDateByOneMillenium(stDate Date, short XCentery=10)
{

	Date.Year += 1000;
	return Date;
}
int main()
{
	stDate Date;
	Date = ReadDate();

	cout << "\n\nDate After : \n\n";
	Date= IncreaseDateByOneDay(Date);
	cout << "01- Adding one day :  " << Date.Day << "/" << Date.Month << "/" << Date.Year<<endl;
	Date = IncreaseDateByXDays(Date, 10);
	cout << "02- Adding 10 days :  " << Date.Day << "/" << Date.Month << "/" << Date.Year<<endl;
	Date = IncreaseDateByOneWeek(Date);
	cout << "03- Adding one week :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByXWeeks(Date,10);
	cout << "04- Adding 10 weeks :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByOneMonth(Date);
	cout << "05- Adding a mounth :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByXMonth(Date, 5);
	cout << "06- Adding 5 mounths :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByOneYear(Date);
	cout << "07- Adding One Year :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByXYear(Date, 10);
	cout << "08- Adding 10 Year :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByOneDecade(Date);
	cout << "07- Adding 10 Year  Faster :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByXYearFaster(Date, 10);
	cout << "10- Adding One Decade  :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByXDecade(Date,10);
	cout << "11- Adding 10 Decades   :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByXDecadeFaster(Date, 10);
	cout << "12- Adding 10 Decades Faster  :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByOneCentery(Date);
	cout << "13- Adding One Centry   :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateByOneMillenium(Date);
	cout << "14- Adding One Millenium  :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	system("pause>0");
}


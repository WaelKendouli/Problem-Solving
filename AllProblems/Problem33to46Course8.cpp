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
stDate DecreaseDateByOneDay(stDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Day = DaysInMounth(Date.Year, Date.Month);
			Date.Year--;

		}
		else
		{
			Date.Month--;
			Date.Day = DaysInMounth(Date.Year, Date.Month);
			
		}
	}
	else
	{
		Date.Day--;
	}
	return Date;
}

stDate DecreaseDateByXDays(stDate Date, short Number)
{
	for (short i = 0; i < Number; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}
stDate DecreaseDateByOneWeek(stDate Date)
{
	return DecreaseDateByXDays(Date, 7);

}
stDate DecreaseDateByXWeeks(stDate Date, short Number)
{

	for (short i = 0; i < Number; i++)
	{
		
			Date = DecreaseDateByOneWeek(Date);
	
	}
	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
	return DecreaseDateByXDays(Date, DaysInMounth(Date.Year, Date.Month + 1));

}
stDate DecreaseDateByXMonth(stDate Date, short Xmonths)
{

	for (short i = 0; i < Xmonths; i++)
	{

		Date = DecreaseDateByOneMonth(Date);

	}
	return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
	Date.Year--;
	return Date;
}
stDate DecreaseDateByXYear(stDate Date, short Xyear)
{

	for (short i = 0; i < Xyear; i++)
	{

		Date = DecreaseDateByOneYear(Date);

	}
	return Date;
}

stDate DecreaseDateByXYearFaster(stDate Date, short Xyear)
{
	Date.Year -= Xyear;

	return Date;
}
stDate DecreaseDateByOneDecade(stDate Date)
{

	return DecreaseDateByXYear(Date, 10);
}
stDate DecreaseDateByXDecade(stDate Date, short XDecade)
{

	for (short i = 0; i < XDecade; i++)
	{

		Date = DecreaseDateByOneDecade(Date);

	}
	return Date;
}

stDate DecreaseDateByXDecadeFaster(stDate Date, short XDecade)
{

	Date.Year -= XDecade * 10;

	return Date;
}

stDate DecreaseDateByOneCentery(stDate Date)
{
	Date.Year -= 100;
	return Date;
}
stDate DecreaseDateByOneMillenium(stDate Date, short XCentery = 10)
{

	Date.Year -= 1000;
	return Date;
}

int main()
{

    stDate Date;
    Date = ReadDate();
	Date = DecreaseDateByOneDay(Date);
	cout << "01- Substracting one day :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXDays(Date, 10);
	cout << "02- Substracting 10 days :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneWeek(Date);
	cout << "03- Substracting one week :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXWeeks(Date, 10);
	cout << "04- Substracting 10 weeks :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneMonth(Date);
	cout << "05- Substracting one month :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXMonth(Date,5);
	cout << "06- Substracting 5 month :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneYear(Date);
	cout << "07- Substracting one year :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXYear(Date, 10);
	cout << "08- Substracting 10 year :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXYearFaster(Date, 10);
	cout << "09- Substracting 10 years (faster) :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneDecade(Date);
	cout << "10- Substracting one Decade :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXDecade(Date,10);
	cout << "11- Substracting 10 Decades :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByXDecadeFaster(Date,10);
	cout << "12- Substracting 10 Decades (faster) :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneCentery(Date);

	cout << "13- Substracting one Centery :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = DecreaseDateByOneMillenium(Date);

	cout << "14- Substracting one Millunium :  " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    system("pause>0");
}



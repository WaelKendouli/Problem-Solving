#include <iostream>

using namespace std;

struct stDate
{
	short year;
	short mounth;
	short day;
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
	short ArrofDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (Mounth < 1 || Mounth > 12)
	{
		return 0;
	}
	return Mounth == 2 ? DaysInMounthTwo(year, Mounth) : (Mounth == ArrofDays[Mounth - 1] ? 31 : 30);
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
void Results(int year, short Mounth, short Days)
{

	cout << "Number Of Days from the begenning of the year is : " << PastDaysInYear(year, Mounth, Days);
}


stDate GetDateFromDayOrder(short year, short PastDaysInYear)
{
	stDate Date;
	Date.year = year;
	Date.mounth = 1;
	short RemainigDays = PastDaysInYear;
	short MounthDays = 0;

	while (true)
	{
		MounthDays = DaysInMounth(year, Date.mounth);
		if (RemainigDays>MounthDays)
		{
			RemainigDays -= MounthDays;
			Date.mounth++;
		}
		else
		{
			Date.day = RemainigDays;
			break;
		}
	}
	return Date;
}
void ShowDate(int year, short Mounth, short Days)
{
	stDate Date;
	short DaysInPastMounths = PastDaysInYear(year, Mounth, Days);
	Date = GetDateFromDayOrder(year, DaysInPastMounths);
	cout << "Date for [" << DaysInPastMounths << "]  : "<<Date.day<<"/"<<Date.mounth<<"/"<<Date.year;
}
int main()
{

	short year = ReadNumber("year");
	short mounth = ReadNumber("Mounth");
	short day = ReadNumber("Day");

	Results(year, mounth, day);
	cout << "\n\n";
	ShowDate(year, mounth, day);
	system("pause>0");
}



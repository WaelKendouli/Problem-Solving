#include <iostream>
#include <string>

using namespace std;


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

short DayInGregorianCalender(short day, short mounth, short year)
{
	short a, y, m;
	a = (14 - mounth) / 12;
	y = year - a;
	m = mounth + (12 * a) - 2;


	return  (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}
string ReturnDateMounth(short Mounth)
{
	string ArrDate[] = { "Jan","Feb","Mar","Apr","May","June","July","Aug","Sep","Oct","Nov","Dec" };
	return ArrDate[Mounth - 1];
}
string DateOfWeek(short DayOfWeek)
{
	string ArrDate[] = { "Sun","Mon","Tue","Wed","Thur","Fri","Sat" };
	return ArrDate[DayOfWeek];
}
void ShowCalender(int year, short Mounth)
{
	short NumberOfDays = DaysInMounth(year, Mounth);
	short OrderOfFirstDayOfMounth = DayInGregorianCalender(1, Mounth, year);

	printf("_______________ %s_______________\n\n", ReturnDateMounth(Mounth).c_str());
	printf(" Sun  Mon  Tue  Wed  Thur  Fri  Sat \n");

	short i;
	for (i = 0; i < OrderOfFirstDayOfMounth; i++)
	{
		printf("     ");

	}
	for (short j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);


		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}

	printf("\n______________________________\n");

}
void YearlyCalender(short year)
{
	printf("\n\n_______________________________\n\n");
	printf("  Calender - %d  ", year);
	printf("\n\n_______________________________\n\n");

	for (short mounth = 1; mounth <= 12; mounth++)
	{
		ShowCalender(year, mounth);

	}


}
int main()
{
	short Year = ReadNumber("year");
	YearlyCalender(Year);
	system("pause>0");
}

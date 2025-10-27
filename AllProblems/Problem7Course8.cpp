#include <iostream>
#include <string>

using namespace std;
enum enDaysOfWeek{Sun=1,Mon=2,Tue=3,Wed=4,Thur=5,Fri=6,Sat=7 };

short ReadNumber(string str)
{
	short Number;
	cout << " Please Enter a " << str << " ?\n";
	cin >> Number;
	return Number;
}
void ShowDate(short day, short mounth, short year)
{
	cout << day << "/" << mounth << "/" << year<<endl;
}

string ReturnDate(enDaysOfWeek DayOfWeek)
{
	string ArrDate[] = { "Sun","Mon","Tue","Wed","Thur","Fri","Sat" };
	return ArrDate[DayOfWeek];
}

short DayInGregorianCalender(short day, short mounth, short year)
{
	short a,y,m;
	a = (14 - mounth) / 12;
	y = year - a;
	m = mounth + (12 * a) - 2;

	
	return  (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	 
}
int main()
{
	short Year = ReadNumber("year");
	short Mounth = ReadNumber("mounth");
	short Day = ReadNumber("day");
	cout << "Date\t:";
	ShowDate(Day, Mounth, Year);
	cout << "Day Order : "<<DayInGregorianCalender(Day,Mounth,Year);
	cout << "\nDay Name : " << ReturnDate((enDaysOfWeek)DayInGregorianCalender(Day, Mounth, Year));
	system("pause>0");
}



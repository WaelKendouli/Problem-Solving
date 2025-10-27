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
	return (!IsDate1BeforeDate2(Date1, Date2)&&!IsDate1EqualDate2(Date1,Date2));
}

int main()
{
	stDate Date1, Date2;
	cout << "Enter Date 1 : \n";
	Date1 = ReadDate();
	cout << "\n\n";
	cout << "Enter Date 2 : \n";
	Date2 = ReadDate();
	cout << "\n\n";
	if (isDate1AfterDate2(Date1, Date2) == true)
		cout << " Yes , Date1 is After Date2 \n";
	else
		cout << "No , Date1 is Not After Date2\n";
    system("pause>0");
}


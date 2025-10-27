#include <iostream>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
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


bool CompareDates(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

string ComparationResult(bool Comparation)
{
	return (Comparation == false) ? "\n\nYes Date 1 is less then Date 2 \n" : "\n\nNo Date 1 is not less then Date 2\n";

}
int main()
{
	stDate Date1;
	stDate Date2;
	Date1 = ReadDate();
	cout << "\n\n";
	Date2 = ReadDate();
	cout << ComparationResult(CompareDates(Date1, Date2));
	system("pause");
}



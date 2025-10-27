#include <iostream>
using namespace std;
enum enmounth{jan=1,fev=2,mar=3,apr=4,may=5,jun=6,jul=7,aug=8,sept=9,octo=10,nov=11,decem=12};
int ReadNumInRange(string str, int from, int to)
{
	int choice;
	do
	{
		cout << str << endl;
		cin >> choice;
	} while (choice<from || choice>to);
	return choice;
}
enmounth MounthReader()
{
	return(enmounth)ReadNumInRange("enter a number from 1 to 12 :", 1, 12);
}
string MounthPrinter(enmounth mounth)
{
	switch (mounth)
	{
	case jan:
		return"Janury";
	case fev:
		return"februry";
	case mar:
		return"March";
	case apr:
		return"April";
	case may:
		return"May";
	case jun:
		return"June";
	case jul:
		return"July";
	case aug:
		return"August";
	case sept:
		return"September";
	case octo:
		return"October";
	case nov:
		return"November";
	case decem:
		return"December";
	default:jan;
		return"Janury";
	}
}
int main()
{
	cout << MounthPrinter(MounthReader());
    return 0;
}
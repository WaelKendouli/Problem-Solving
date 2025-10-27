#include <iostream>
using namespace std;

enum endays{ sunday=1 , monday=2 , tueday=3 , wedenday=4, thursday=5 , friday =6 , saturday=7 };
void menu()
{
	cout << "\n**************************\n";
	cout << "		week days	 " << endl;
	cout << "\n**************************\n";
	cout<<" sunday :1"<<endl;
	cout<<" monday :2"<<endl;
	cout<<" tuesday :3"<<endl;
	cout<<" wednsday :4"<<endl;
	cout<<" thursday :5"<<endl;
	cout<<" friday :6"<<endl;
	cout << " saturday :7" << endl;
}
int ReadNumInRange(string str  , int from , int to)
{
		 int choice ;
	do
	{
		cout << str<<endl;
	cin >> choice;
	} while (choice<from||choice>to);
	return choice;
}
endays day_enter(  )
{

	return (endays)ReadNumInRange("enter a number from 1 to 7 :", 1, 7);
}
string weekdeter(endays weekday)
{
	switch (weekday)
	{
	case sunday:
		return "sunday";
		
	case monday:
		return"monday";
		
	case tueday:
		return"tueday";
		
	case wedenday:
		return"wedenday";
		
	case thursday:
		return"thursday";
		
	case friday:
		return"friday";
		
	case saturday:
		return "saturday";
		
	default:
		return "not a day!";
		
	}
}

int main()
{

	menu();
	
	cout << "today is : " << weekdeter(day_enter());
		

	return 0;
}

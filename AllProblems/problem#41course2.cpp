

#include <iostream>
using namespace std;
float ReadNumberOfHours(string str)
{
	float hours;
	cout << str;
	cin >> hours;
	return hours;
}
float CalcNumberOfdays(float Hours)
{
	
		return Hours / 24;
 
}
float CalcNumberOfWeeks(float days)
{
	 return  days / 7;
}
int main()
{
	 float days = CalcNumberOfdays(ReadNumberOfHours("Enter Hours :"));
	 float weeks = CalcNumberOfWeeks(days);
	 cout << "\n********************\n";
	 cout << "Days = "<<endl << days <<endl;
	 cout << "Weeks = "<<endl << weeks;

	return 0;
}


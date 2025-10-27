#include <iostream>
#include<string>
using namespace std;
int readnumber()
{
	int number;
	cout << "give a number : " << endl;
	cin >> number;
	return number;
}
float calcnumber(int number)
{
	return (float)number / 2;
}
void showresults( int number)
{
	string result = " half of " + to_string(number) + " is " + to_string(calcnumber(number));
	cout << result << endl;
}
int main()
{
	showresults( readnumber());
}



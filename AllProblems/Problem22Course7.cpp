

#include <iostream>
using namespace std;
short int ReadNumber(string str)
{
	short int Number;
	cout << str << endl;
	cin >> Number;
	return Number;
}
void RecursiveFibbonachiSeries(short int FibbonachiNumber, short int prev, short int prev2)
{
	short int number = 0;
	if(FibbonachiNumber>=0)
	{
	number = prev + prev2;
	prev2 = prev;
	prev = number;
	cout << number << "\t";
	RecursiveFibbonachiSeries(FibbonachiNumber - 1, prev, prev2);
	}

	
	
}
int main()
{
	RecursiveFibbonachiSeries(ReadNumber("give a number :"), 1, 0);

	return 0;
}



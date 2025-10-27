

#include <iostream>
using namespace std;
short int ReadNumber(string str)
{
	short int Number;
	cout << str << endl;
	cin >> Number;
	return Number;
}

void FibbonachiSeries(short int FibbonachiNumber)
{
    short int prev = 1;
	short int prev2 = 0;
	short int number;
	for (short int  i = 1; i <= FibbonachiNumber-1; i++)
	{
		number = prev + prev2;
		cout << number << "\t";
		prev2 = prev;
		prev = number;
		
	}
}	
int main()
{
	FibbonachiSeries(ReadNumber("give a number :"));
	return 0;
}





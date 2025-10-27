#include <iostream>
using namespace std;
int ReadNumber(string str)
{
	int Number;
	do
	{
		cout << str << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}
int ReversedNumber(int Number)
{
	int Remain , Number2=0;
	while (Number>0)
	{

		Remain = Number % 10;
		Number = Number / 10;
		Number2 = Number2 * 10 + Remain;
	}
	return Number2;
}

int main()
{
	cout<<"\nReversed :\n"<< ReversedNumber(ReadNumber(" number :"));

}



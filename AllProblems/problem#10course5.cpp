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
void NumberToDigit(int Number)
{
	int Remain  ;
	
	while (Number>0)
	{
		Remain = Number % 10;
			Number = Number / 10;
			cout << Remain<<endl;
	}
}
int ReversedNumber(int Number)
{
	int Number2 = 0,Remain;
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
	NumberToDigit(ReversedNumber(ReadNumber(" Number ? : ")));

}




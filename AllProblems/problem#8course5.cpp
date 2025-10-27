#include<iostream>
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
int DetectAndCountDigit(int N ,int Digit)
{
	int  counter=0;
	int Remain;

	while (N > 0)
	{
		Remain = N % 10;
		if (Remain == Digit)
			counter = counter + 1;
		N = N / 10;
	}
	return counter;
}

int main()
{
	int Digit = ReadNumber("Digit :");
	int N = ReadNumber("Number :");
	cout << "Your " << Digit << " Frequency is " << DetectAndCountDigit(N, Digit) << " Time(s) ";
}
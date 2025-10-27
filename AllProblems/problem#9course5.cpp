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
int DetectAndCountDigit(int N, short Digit)
{
	int  counter = 0;
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
void PrintAllDigits(int Number)
{
	for (int i = 0; i < 10; i++)
	{
	short DigitFrequency = 0;
	DigitFrequency = DetectAndCountDigit(Number, i);
	if (DigitFrequency > 0)//means if the digit existed
	{
		cout << " Digit " << i << " Frequancy is " << DigitFrequency << " Time(s) " << endl;
	}
	}


}

int main()
{
	short Digit = ReadNumber("Digit :");
	int N = ReadNumber("Number :");
	PrintAllDigits(N);
}

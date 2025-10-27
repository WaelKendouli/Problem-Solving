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
int SumOfDigits(int Number)
{
	int Remain;
	int Sum=0;
	while (Number>0)
	{
		Remain = Number % 10;
		Sum = Sum + Remain;
		Number = Number / 10;
	}
	return Sum;
}
void ResultOfSum()
{
	cout << "Sum Of Digits = " << SumOfDigits(ReadNumber("Number ? :"));
}
int main()
{
	ResultOfSum();

}



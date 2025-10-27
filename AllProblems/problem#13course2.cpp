#include <iostream>
using namespace std;
void readnumbers(int& number1,int& number2,int& number3)
{
	cout << "Number 1 :" << endl;
	cin >> number1;
	cout << "Number 2 :" << endl;
	cin >> number2;
	cout << "Number 3 :" << endl;
	cin >> number3;
}
int checkMaxNumber(int number1,int number2,int number3)
{
	if (number1 > number2)
		if (number1 > number3)
			return number1;
		else
			return number3;
	if (number2 > number1)
		if (number2 > number3)
			return number2;
		else
			return number3;

}
void PrintResultOfMaxNumber(int max)
{
	
	cout << "Max = " << max << endl;
}
int main()
{
	int number1, number2, number3;
	readnumbers(number1, number2, number3);
	PrintResultOfMaxNumber(checkMaxNumber(number1, number2, number3));

}

#include <iostream>
using namespace std;

float ReadNumber()
{
	float Number;
	cout << "Number : \n";
	cin >> Number;
	return Number;
}
float GetFractionPart(float Number)
{
	return Number - int(Number);
}
int MyRoundFunction(float Number)
{
	int IntegerPart;
	IntegerPart = (int)Number;
	float FractionPart = GetFractionPart(Number);
	if (abs(FractionPart) >= 0.5)
	{
		return ++IntegerPart;
	}
	else
	{
		return --IntegerPart;
	}
	return IntegerPart;
}

int main()
{
	float Number = ReadNumber();
	cout << "\n";
	cout << "My round Funtion : "<<MyRoundFunction(Number);
	cout << "\n";
	cout << "C++ round Function : " << round(Number);
}

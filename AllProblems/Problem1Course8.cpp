#include <iostream>
#include <string>
using namespace std;

string NumberToText(int Number)
{
	if (Number == 0)
	{
		return "";
	}
	if (Number >= 1 && Number <= 19)
		{ 
			string arr[] = { "","one","two","three","four","five","six","seven"
			"eigth","nine","ten","eleven","twelve","fourteen","fiveteen","sixteen",
			"seventeen","eigthteen","ninetheen" };

			return arr[Number] + " ";
		}

	if (Number >= 20 && Number <= 99)
	{
		string arr[] = { "","","twenty","therty","fourty","fivety","sixty","seventy"
			"eigthy","ninety"};

		return arr[Number / 10] + " " + NumberToText(Number % 10);
	}

	if (Number >= 100 && Number <= 199)
	{
		return "One hundred " + NumberToText(Number % 10);
	}

	if (Number >= 200 && Number <= 999)
	{
		return NumberToText(Number / 100) + " Hundred " + NumberToText(Number % 100);
	}
	if (Number >= 1000 && Number <= 1999)
	{
		return "One thousand " + NumberToText(Number % 1000);
	}
	if (Number >= 2000 && Number <= 999999)
	{
		return NumberToText(Number / 1000) + " thousands " + NumberToText(Number % 1000);
	}
	if (Number >= 1000000 && Number <= 1999999 )
	{
		return "One million " + NumberToText(Number % 1000000);
	}
	if (Number >= 2000000 && Number <= 99999999)
	{
		return NumberToText(Number / 1000000) + " millions " + NumberToText(Number % 1000000);
	}
	if (Number >= 1000000000 && Number <= 1999999999)
	{
		return "One billion " + NumberToText(Number % 1000000000);

	}
	else
	{
		return NumberToText(Number / 1000000000) + " billions " + NumberToText(Number % 1000000000);
	}
}
int ReadNumber()
{
	int Number;
	cout << "Enter a Number\n";
	cin >> Number;
	return Number;
}
int main()
{
	int Number = ReadNumber();
	cout << NumberToText(Number);
	return 0;
}



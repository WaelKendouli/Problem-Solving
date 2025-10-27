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
void PrintInvertedPattren()
{
	int Number = ReadNumber("Number : ");
	for (int i = Number; i  >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
		cout << "\n";

	}
}

int main()
{
	PrintInvertedPattren();
}



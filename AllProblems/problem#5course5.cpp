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
void NumberToDigits(int N)
{
	int i = N ;
	int Remain ;
	while (N>0)
	{
		Remain = N % 10;
		N = N / 10;
		cout << Remain<<endl;	
	}
}

int main()
{
	NumberToDigits(ReadNumber("Number ? :"));
}



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
bool SumAllDivisors(int N)
{
	int S = 0;

	for (int i = 1; i < N; i++)
	{
		if (N % i == 0)
		{
			S = S + i;
		}
	}
	return N == S;
}

void PrintResult()
{
	int N = ReadNumber("Number ? :");
	for (int j = 1; j < N; j++)
	{
		if (SumAllDivisors(j) == true)
			cout << j << endl;
	}
}
int main()
{
	PrintResult();
}




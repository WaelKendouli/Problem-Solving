#include <iostream>
using namespace std;
enum enPrimeOrNot{prime=1,NotPrime=2};
int ReadNumber(string str)
{
	int Number;
	do
	{
		cout << str << endl;
		cin >> Number;
	} while (Number<=0);
	return Number;
}
enPrimeOrNot CheckIfPrime( int N)
{
	
	for (int i = 1; i <= N / 2; i++)
	{
		if (N % i != 0)
			return enPrimeOrNot::prime;
		else
			return enPrimeOrNot::NotPrime;
	}
}
void PrintTestingPrime(int N)
{
	
	
for (int i = 1; i <=N; i++)
	{
	if (CheckIfPrime(N) == enPrimeOrNot::prime)
		cout << i ;
	}
}

int main()
{
	PrintTestingPrime(ReadNumber("Number ? :"));
}


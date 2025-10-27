#include <iostream>
using namespace std;
enum enPrimeOrNot {Prime=1,NotPrime=2};
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
enPrimeOrNot testPrimeNumber()
{
	
	int Number = ReadNumber("Number ? :");
	for (int i = 2; i <= Number/2; i++)
	{
		if (Number % i == 0)
		{
			return enPrimeOrNot::NotPrime;
		}
		else
			return enPrimeOrNot::Prime;
	}
}
void PrintPrimeOrNot()
{
	if (testPrimeNumber() == enPrimeOrNot::Prime)
		cout << "prime";
	else
		cout << "Not prime";

}
int main()
{
	PrintPrimeOrNot();

	return 0;
}

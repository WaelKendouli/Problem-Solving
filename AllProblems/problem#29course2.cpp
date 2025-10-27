#include <iostream>
using namespace std;



enum enOddOrEven { odd = 1, even = 2 };
int ReadNumber()
{
	int N;
	cout << "Number :" << endl;
	cin >> N;
	return N;
}
enOddOrEven ConditionSumOddNumber(int N)
{
	if (N % 2 != 0)
		return enOddOrEven::odd;
	else
		return enOddOrEven::even;
}
int ForLoopFrom1ToN(int N)
{
	int S = 0;
	for (int i = 1; i <= N; i++)
	{
		if (ConditionSumOddNumber(i) == enOddOrEven::even)
		{
			S = S + i;
		}
	}
	return S;
}
int whileLoopFrom1ToN(int N)
{
	int S = 0;
	int i = 1;
	while (i <= N)
	{
		if (ConditionSumOddNumber(i) == enOddOrEven::even)
		{
			S = S + i;
		}
		i++;
	}
	return S;
}
int DoWhileLoopFrom1ToN(int N)
{
	int S = 0, i = 1;
	do
	{
		if (ConditionSumOddNumber(i) == enOddOrEven::even)
		{
			S = S + i;
		}
		i++;
	} while (i <= N);
	return S;
}
int main()
{
	int N = ReadNumber();
	cout << ForLoopFrom1ToN(N)<<endl;
	cout << whileLoopFrom1ToN(N) << endl;
	cout << DoWhileLoopFrom1ToN(N)<<endl;
	return 0;

}



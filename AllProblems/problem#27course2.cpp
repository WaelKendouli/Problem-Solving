#include <iostream>
using namespace std;
int ReadNumber()
{
	int N;
	cout << "Number : " << endl;
	cin >> N;
	return N;
}
void ForLoopDisplay(int N)
{
	for (int i = N; i >=1; i--)
	{
		cout << i << endl;
	}

}
void WhileLoopDisplay(int N)
{
	int i = N;
	while (i >= 1)
	{
		cout << i << endl;
		i--;
	}
}
void DoWhileLoopDisplay(int N)
{
	int i = N;
	do
	{
		cout << i << endl;
		i--;
	} while (i >= 1);
}

int main()
{
	int N = ReadNumber();

	cout << "_____________________________" << endl;
	ForLoopDisplay(N);
	cout << "_____________________________" << endl;
	WhileLoopDisplay(N);
	cout << "_____________________________" << endl;
	DoWhileLoopDisplay(N);
	cout << "_____________________________" << endl;

}


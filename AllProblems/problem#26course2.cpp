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
for (int i = 1; i <= N; i++)
	{
		cout << i << endl;
	}

}
void WhileLoopDisplay(int N)
{
	int i = 1;
	while (i <= N)
	{
		cout << i << endl;
		i++;
	}
}
void DoWhileLoopDisplay(int N)
{
	int i = 1;
	do
	{
		cout << i << endl;
		i++;
	} while (i <= N);
}

int main()
{
	int N = ReadNumber();

	cout << "_____________________________"<<endl;
	ForLoopDisplay(N);
	cout << "_____________________________" << endl;
	WhileLoopDisplay(N);
	cout << "_____________________________" << endl;
	DoWhileLoopDisplay(N);
}





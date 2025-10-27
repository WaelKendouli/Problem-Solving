#include <iostream>
using namespace std;


void HeadOfTheMultiTable()
{	
	cout << "\n\n\t\t" << "Multiplication Table From  1 to   10 \t\t\n\n" << endl;
	for (int i = 1; i <= 10; i++)
	{
		cout << "\t" << i;
	}
	cout << "\n";
	cout << "____________________________________________________________________________________________" << endl;

}

string ColomnSparater(int i)
{
	if (i < 10)
		return"   |";
	else
		return"  |";
}
void ContentOfMultiTable()
{
	HeadOfTheMultiTable();
	for (int i = 1; i <= 10; i++)
	{	
		cout << " " << i << ColomnSparater(i) << "\t";

		for (int j = 1; j <= 10; j++)
		{
			cout << i * j << "\t";
		}
		cout << "\n";
	}
}

int main()
{
	ContentOfMultiTable();
}


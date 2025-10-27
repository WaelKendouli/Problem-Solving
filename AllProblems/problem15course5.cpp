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
void PrintLettersPattren(int Number)
{
	cout << "\n";
	for (int i = 65; i <= Number+65-1; i++)
	{
		for (int j = 1; j <= Number-(65+Number-1-i); j++)
		{
			cout << char(i);
		}
		cout << "\n";


	}


}

int main()
{
	PrintLettersPattren(ReadNumber("Number : "));
}


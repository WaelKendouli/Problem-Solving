#include <iostream>
#include <cstdlib>
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
int RandomNumber(short int from, short int To)
{
	return rand() % ((To - from + 1) + from);
}
void fillArray(int Size, int arr[100])
{

	for (int i = 0; i <= Size - 1; i++)
	{
		arr[i] = RandomNumber(1, 100);

	}
	cout << "\n";
}
void DisplayArray(int& size, int arr[100])
{
	for (int i = 0; i <= size - 1; i++)
	{
		cout << arr[i] << " ";
	}

}
int CountEvenElements(int& size, int arr[100])
{
	int CountOdd = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] % 2 == 0)
			CountOdd = CountOdd + 1;
	}
	return CountOdd;
}


int main()
{
	srand((unsigned)time(NULL));
	int size = ReadNumber("Array length :");
	int arr[100];
	fillArray(size, arr);
	cout << "Array Elements : " << endl;
	DisplayArray(size, arr);
	cout << "\n";

	cout << "Even Numbers Count Is : " << CountEvenElements(size, arr);

	return 0;
}

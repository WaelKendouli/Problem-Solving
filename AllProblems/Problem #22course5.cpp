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
void FillArray(int Size ,int	arr[10])
{
	
	
	for (int i = 1; i <= Size; i++)
	{
		cout << "Element [" << i << "] :  ";
		cin >> arr[i] ;

	}
	
}
void DisplayArray(int Size, int	arr[10])
{
	cout << "\n\n";
	cout << "Original Array : ";
	for (int i = 1; i <= Size ; i++)
	{
		cout << arr[i]<<" ";

	}
	cout << "\n\n";

}
void ElementCountArray(int Size, int	arr[10])
{
	int c=0, SearchNumber = ReadNumber("Enter the number you want to check :");
	cout << "\n\n";

	for (int i = 1; i <= Size ; i++)
	{
		if (arr[i] == SearchNumber)
		{
			c=c+1;
		}
		
	}
	cout << SearchNumber << " is repeated " << c << " time(s) ";
}

int main()
{
	int arr[9];
	int Size = ReadNumber("Size :");
	FillArray(Size,arr);
	DisplayArray(Size, arr);
	ElementCountArray(Size, arr);

}


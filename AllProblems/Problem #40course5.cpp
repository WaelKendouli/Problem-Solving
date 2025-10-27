#include <iostream>
#include<string>
using namespace std;
enum enDistinctOrNot { Distinct, NotDistinct };


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
short int FindPositionInArray(int arr[100], int Input, int size)
{
	for (int i = 0; i <= size; i++)
	{
		if (arr[i] == Input)
			return i;


	}
	return -1;//means not found
}

void fillArray(int& Size, int	arr[100])
{


	for (int i = 0; i <= Size - 1; i++)
	{
		arr[i] = ReadNumber("Enter the " + to_string(i) + " th Element");
		cout << "\n";

	}
	
}
void DisplayArray(int& size, int arr[100])
{
	for (int i = 0; i <= size - 1; i++)
	{

		cout << arr[i] << " ";
	}


}
void AddArrayElement(int Number, int arr[100], int& Size)
{
	Size++;
	arr[Size - 1] = Number;
}

void CopyArrayUsingAddArrayElement(int& Size, int& Size2, int	arr[100], int arr2[100])
{

	for (int i = 0; i <= Size - 1; i++)
	{
		
for (int j = i+1; j < Size; j++)
		{
			if (arr[i] != arr[j])
				AddArrayElement(arr[i], arr2, Size2);

		}
	}
}

int main()
{

	
	int Size = ReadNumber("Size : ");
	int arr[100];
	fillArray(Size, arr);
	cout << "Array 1 elements : " << endl;
	DisplayArray(Size, arr);
	cout << "\n";
	cout << "Array 2 elements : " << endl;

	int arr2[100];
	int SizeArr2 = 0;
	CopyArrayUsingAddArrayElement(Size, SizeArr2, arr, arr2);
	DisplayArray(SizeArr2, arr2);
}

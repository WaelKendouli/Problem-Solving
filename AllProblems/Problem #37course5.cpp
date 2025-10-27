#include <iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(int from, int To)
{
	return rand() % ((To - from + 1) + from);
}

int ArrayLength()
{
	int Size;
	do
	{
		cout << "Size : " << endl;
		cin >> Size;
	} while (Size <= 0);

	return Size;

}

void fillArrayRandom(int& Size, int	arr[100])
{


	for (int i = 1; i <= Size; i++)
	{
		arr[i] = RandomNumber(1, 100);


	}
	cout << "\n\n";


}
void DisplayArray(int& size, int arr[100])
{
	for (int i = 1; i <= size; i++)
	{
		cout << arr[i] << " ";
	}


}
void AddArrayElement(int Number, int arr[100], int& Size)
{
	Size++;
	arr[Size - 1] = Number;
}
void CopyArrayUsingAddArrayElement(int& Size,int& Size2, int	arr[100], int arr2[100])
{

	for (int i = 0; i <= Size; i++)
	{

		AddArrayElement(arr[i], arr2, Size2);

	}
}

int main()
{

	srand((unsigned)time(NULL));
	int Size = ArrayLength();
	int SizeArr2 = 0;
	int arr[100];
	int arr2[100];
	fillArrayRandom(Size, arr);
	cout << "Array 1 elements : " << endl;
	DisplayArray(Size, arr);
	cout << "\n";
	cout << "Array 2 elements : " << endl;
	CopyArrayUsingAddArrayElement(Size,SizeArr2, arr, arr2);
	DisplayArray(Size, arr2);
}

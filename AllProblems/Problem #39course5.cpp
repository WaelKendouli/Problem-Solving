#include <iostream>
#include<cstdlib>
using namespace std;
enum enPrimeOrNot {Prime,NotPrime};
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


	for (int i = 0; i <= Size - 1; i++)
	{
		arr[i] = RandomNumber(1, 100);


	}
	cout << "\n\n";


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
enPrimeOrNot CheckIfPrimeElemnt(int Number)
{
	for (int i = 2; i <= Number/2; i++)
	{
		if (Number % i == 0)
			return enPrimeOrNot::Prime;
		else
			return enPrimeOrNot::NotPrime;
	}
	
}
void CopyArrayUsingAddArrayElement(int& Size, int& Size2, int	arr[100], int arr2[100])
{

	for (int i = 0; i <= Size - 1; i++)
	{
		if (CheckIfPrimeElemnt(arr[i])==enPrimeOrNot::Prime)
		{
			AddArrayElement(arr[i], arr2, Size2);
		}


	}
}

int main()
{

	srand((unsigned)time(NULL));
	int Size = ArrayLength();
	int arr[100];
	fillArrayRandom(Size, arr);
	cout << "Array 1 elements : " << endl;
	DisplayArray(Size, arr);
	cout << "\n";
	cout << "Array 2 elements : " << endl;

	int arr2[100];
	int SizeArr2 = 0;
	CopyArrayUsingAddArrayElement(Size, SizeArr2, arr, arr2);
	DisplayArray(SizeArr2, arr2);
}

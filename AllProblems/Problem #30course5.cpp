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
	cout << "\n";


	for (int i = 0; i < Size; i++)
	{
		arr[i] = RandomNumber(1, 100);


	}
	cout << "\n";
}
void DisplayArray(int& size, int arr[100])
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}


}
void SumOf2Arrays(int arr[100], int arr2[100], int arr3[100], int& size)
{
	
	for (int  i = 0; i < size; i++)
	{
		arr3[i] = arr[i] + arr2[i];
		
	}
	
}
int main()
{
	srand((unsigned)time(NULL));
	int SizeOf2Arrays = ArrayLength();
	int arr[100], arr2[100], arr3[100];
	
	fillArrayRandom(SizeOf2Arrays, arr);
	cout << "Array 1 elements : " << endl;
	DisplayArray( SizeOf2Arrays,arr );
	cout << "\n";
	fillArrayRandom(SizeOf2Arrays, arr2);
	cout << "Array 2 elements : " << endl;
	DisplayArray(SizeOf2Arrays, arr2);
	cout << "\n\n";
	cout << "Sum of The previous arrays :" << endl;
	SumOf2Arrays(arr, arr2, arr3, SizeOf2Arrays);
	DisplayArray(SizeOf2Arrays, arr3);
	cout << "\n\n";

}


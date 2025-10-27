#include <iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(short int from, short int To)
{
	return rand() % ((To - from + 1) + from);
}
int ArrayLength()
{
	int Size=0;
	do
	{
		cout << "Size : " << endl;
		cin >> Size;
	} while (Size <= 0);

	return Size;

}
void fillArray(int Size, int	arr[100])
{
	cout << "\n";


	for (int i = 0; i < Size-1; i++)
	{
		arr[i] = RandomNumber(1,100);

	}
	cout << "\n";
}
void DisplayArray(int size, int arr[100])
{
	for (int i = 0; i < size-1; i++)
	{
		cout << arr[i] << " ";
	}


}

void CopyArrayInReversedOrder(int Size, int	arr[100], int arr2[100])
{

	for (int i = 0; i < Size-1; i++)
	{

		arr2[i] = arr[Size-1-i];

	}
}

int main()
{
	srand((unsigned)time(NULL));
	int size = ArrayLength();
	int arr[100];
	int arr2[100];
	cout << "Array 1 element : " << endl;
	fillArray(size, arr);
	cout << "\n";
	CopyArrayInReversedOrder(size, arr, arr2);

	DisplayArray(size, arr);
	cout << "\n\n";
	cout << "Array 2 after coping Array 1 in reverse order : " << endl;
	//CopyArrayInReversedOrder(size, arr, arr2);
	DisplayArray(size, arr2);


}



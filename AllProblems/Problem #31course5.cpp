#include <iostream>
#include<cstdlib>
using namespace std;
void Swap(int& A, int& B)
{
	int C;
	C = A;
	A = B;
	B = C;

}
int RandomNumber( short int from,short int To)
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
void fillArray(int& Size, int	arr[100])
{
	cout << "\n";


	for (int i = 0; i < Size; i++)
	{
		arr[i] = i+1;

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
void ShuffelArrayElements(int& size, int ArrSource[100])
{
	for (int i = 0; i < size; i++)
	{
	
		 Swap(ArrSource[RandomNumber(1, size) - 1], ArrSource[RandomNumber(1, size) - 1]);

	}

}
int main()
{
	srand((unsigned)time(NULL));
	int size = ArrayLength();
	int arr[100];
	cout << "Array 1 element : " << endl;
	fillArray(size, arr);
	cout << "\n";
	DisplayArray(size, arr);
	cout << "\n\n"; 
	cout << "Array element after shuffel : " << endl;
	ShuffelArrayElements(size, arr);
	DisplayArray(size, arr);
	cout << "\n";

	return 0;
}


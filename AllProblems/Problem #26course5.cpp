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

void DisplayArrayRandom(int& Size, int	arr[100])
{

	cout << "\n\n";
	cout << " Array Elements : ";
	for (int i = 1; i <= Size; i++)
	{
		arr[i] = RandomNumber(1, 100);
		cout << arr[i] << " ";

	}
	cout << "\n\n";


}
int SumArrayElement(int& Size, int	arr[100])
{
	int Sum = 0;
	for (int i = 1; i <= Size; i++)
	{
		arr[i] = RandomNumber(1, 100);
		Sum = Sum + arr[i];

	}
	cout << "\n\n";
	return Sum;
}


int main()
{
	srand((unsigned)time(NULL));
	int Size = ArrayLength();
	int arr[100];
	DisplayArrayRandom(Size, arr);
	cout << "Sum Array is : " <<SumArrayElement(Size, arr);
}



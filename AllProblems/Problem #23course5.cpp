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
	} while (Size<=0);
	
	return Size;
	
}
void DisplayArrayRandom(int Size, int	arr[10])
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
int main()
{
	srand((unsigned)time(NULL));

	int Size=ArrayLength(), arr[10];

	DisplayArrayRandom(Size, arr);
	return 0;
}



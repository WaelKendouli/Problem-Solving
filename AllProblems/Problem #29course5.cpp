#include <iostream>
#include<cstdlib>
using namespace std;
enum enPrimeOrNot{Prime,NotPrime};
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
enPrimeOrNot TestIfPrime(int N)
{
	for (int i = 2; i <= N/2; i++)
	{
		if (N % i != 0)
			return enPrimeOrNot::Prime;
		else
			return enPrimeOrNot::NotPrime;
	}

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
void CopyPrimeArrayElem(int& Size, int	arr[100], int arr2[100], int& SizeArr2)
{
	int counter = 1;
	for (int i = 1; i <= Size; i++)
	{
		if (TestIfPrime(arr[i])==enPrimeOrNot::Prime)
		{
			arr2[counter] = arr[i];
			
		}
	}
	SizeArr2 = counter;
}

int main()
{

	srand((unsigned)time(NULL));
	int Size = ArrayLength();
	int arr[100];
	int arr2[100],SizeArr2=0;
	fillArrayRandom(Size, arr);
	cout << "Array 1 elements : " << endl;
	DisplayArray(Size, arr);
	cout << "\n";
	cout << "Array 2 prime elements : " << endl;
	CopyPrimeArrayElem(Size, arr, arr2,SizeArr2);
	DisplayArray(SizeArr2, arr2);
}

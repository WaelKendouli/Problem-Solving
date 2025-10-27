#include <iostream>
#include<cstdlib>
using namespace std;
int ReadNumber(string str)
{
	int N;
	do
	{
		cout << str << endl;
		cin >> N;
	} while (N <= 0);

	return N;

}
int RandomNumber(short int from, short int To)
{
	return rand() % ((To - from + 1) + from);
}
void fillArray(int Size, int	arr[100])
{
	cout << "\n";


	for (int i = 0; i <= Size - 1; i++)
	{
		arr[i] = RandomNumber(1, 100);

	}
	cout << "\n";
}
void DisplayArray(int size, int arr[100])
{
	for (int i = 0; i <= size - 1; i++)
	{
		cout << arr[i] << " ";
	}


}
 short int FindPositionInArray(int arr[100],int Input,int size)
{
	for (int i = 0; i <= size; i++)
	{
		if (arr[i] == Input)
			return i;
		
			
	}
	return -1;//means not found
}


int main()
{
	srand((unsigned)time(NULL));
	int size = ReadNumber("Array length :");
	int arr[100];
	fillArray(size, arr);
	DisplayArray(size, arr);
	cout << "\n";
	int SearchingNumber = ReadNumber("Please enter a number to search for ? :\n");
	short int position = FindPositionInArray(arr, SearchingNumber, size);
	if (position==-1)
	{

		cout << "\nThe number you are looking for is : " << SearchingNumber << endl;
		cout << "The Number is Not Found :-(\n";

	}
	else

	{
cout << "\nThe number you are looking for is : " <<SearchingNumber << endl;
			cout << "found at position : " << position << endl;
			cout << "The Number found it's order : " << position + 1 << endl;
	}
	
	return 0;
}



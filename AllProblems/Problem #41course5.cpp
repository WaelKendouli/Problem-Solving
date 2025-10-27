#include <iostream>
#include <string>

using namespace std;
enum enPalindromOrNot
{
	Palindrom , NotPalindrom
};
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
void DisplayArray(int& size, int arr[100])
{
	for (int i = 0; i <= size - 1; i++)
	{

		cout << arr[i] << " ";
	}


}
bool CheckIfPalindrom(int arr[100],int& Size)
{
	for (int  i = 0; i <Size-1 ; i++)
	{
		if (arr[i]!=arr[Size-i-1])
		{
			return false;
		}
	}
	return true;
}
void fillArray(int& Size, int	arr[100])
{


	for (int i = 0; i <= Size - 1; i++)
	{
		arr[i] = ReadNumber("Enter the " + to_string(i) + " th Element");
		cout << "\n";

	}

}
string ShowResults(int arr[100], int& Size)
{
	if (CheckIfPalindrom(arr, Size))
		return"\n Palindrom array \n";
	else
		return "\n Not Palindrom Array \n";
}
int main()
{
	int Size = ReadNumber("Size : ");
	int arr[100];
	fillArray(Size, arr);
	cout << "\n Array Elements : " << endl;
	DisplayArray(Size, arr);
	cout << ShowResults(arr, Size);



	return 0 ;
}


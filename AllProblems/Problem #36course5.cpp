#include <iostream>
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

void DisplayArray(int& size, int arr[100])
{
	for (int i = 0; i < size ; i++)
	{
		cout << arr[i] << " ";
	}


}
void AddArrayElement(int Number,int arr[100],int& Size)
{
	Size++;
	arr[Size - 1] = Number;
}
void CreateSemiDynamicArr(int arr[100], int& DynSize)

{
	
	bool choice;
	
	do
	{

	AddArrayElement( ReadNumber("Please enter a number ? :"), arr, DynSize);
		
		
		cout << "\n";
		do
		{
cout << "Do you want to add more numbers ? :[0] No , [1] yes"<<endl;
		cin >> choice;
		} while (choice  < 0 || choice > 1);
		
		
			
		
		
	} while (choice==true);
	

}
int main()
{
	int DynSize = 0;
	int arr[100];
	CreateSemiDynamicArr(arr,DynSize);
cout << "Array length :" << DynSize;
	cout << "\n";
	cout << "Array element :\n";
	DisplayArray(DynSize ,arr);
	return 0;
}


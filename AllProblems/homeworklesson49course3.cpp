#include <iostream>
using namespace std;
void nestedloopletters_1()
{
	for (char i = 'A'; i <='Z'; i++)
	{
		for (char j = 'A'; j <='Z'; j++)
		{
			cout << i << j << endl;
		}
	}

}
void stars_triangle()
{
	int n;
	cout << "number of lines : " << endl;
	cin >> n;
	for (int i = n; i >=1; i--)
	{
		
		for (int j = i; j >= 1; j--)
		{
			cout << "*";
		}
		cout << "\n";
	}
}
void letters_tringle()
{
	char c;
	cout << "your capital letter : " << endl;
	cin >> c;
	for (char i ='A'; i <=c; i++)
	{
		
		for (char j = 'A'; j <=i; j++)
		{
			 cout << j;
		}
		cout << "\n";

	}
}
void numbers_triangle()
{
	int num;
	cout << "number of lines : " << endl;
	cin >> num;
	for (int i = 1; i <=num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j;
		}
		cout << "\n";
	}
}
void reversed_numbers_triangle()
{
	int num;
	cout << "number of lines : ";
	cin >> num;
	for (int i = num; i >= 1; i--)
	{
		for (int j = 1; j <=i; j++)
		{
			cout << j;
		}
		cout << "\n";
	}
}
void reversed_stars_triangle()
{
	int nol;
	cout << "Number of lines :";
	cin >> nol;
	for (int i = nol; i >= 1; i--)
	{
		for (int j = 1; j <=i; j++)
		{
			cout<<"*";
		}
		cout << "\n";
	}

}

int main()
{
	//nestedloopletters_1();
	//starstriangle();
	//letters_tringle();
	//numbers_triangle();
	//reversed_numbers_triangle();
	//reversed_stars_triangle();
	return 0;
}


#include <iostream>
using namespace std;
void ReadNumbers(int &Number1,int &Number2)
{
	cout << "enter 2 numbers : \n";
	cin >> Number1 >> Number2;
}
void SwappNumbers(int& Number1, int& Number2)
{
	int Number3;
	Number3 = Number1;
	Number1 = Number2;
	Number2 = Number3;
}
void PrintNumbers(int Number1, int Number2)
{
	
	cout << Number1 << "   " << Number2<<endl;
}
int main()
{
	int Number1, Number2;
	ReadNumbers(Number1, Number2);
	PrintNumbers(Number1, Number2);
	SwappNumbers(Number1, Number2);
	PrintNumbers(Number1, Number2);
	return 0;
}


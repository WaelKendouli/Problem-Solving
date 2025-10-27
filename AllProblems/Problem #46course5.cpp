#include <iostream>
using namespace std;
int MyAbsFunction(int Number)
{
	if (Number > 0)
		return Number;
	else
		return -Number;
}

int main()
{
	int Input;
	cout << "Number : \n";
	cin >> Input;
	cout << "My abs function : " << MyAbsFunction(Input);
	cout << "\n";
	cout << "C++ abs function : " << abs(Input);
	return 0;
}


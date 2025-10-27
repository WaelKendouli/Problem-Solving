#include <iostream>
using namespace std;
float ReadNumber()
{
	float Number;
	cout << "Number : \n";
	cin >> Number;
	return Number;
}
int MyCielFunction(float Number)
{
	if (Number > 0)
	{
		return (int)++Number;
	}
	else
	{
		return (int)Number;
	}

}


int main()
{
	float Number = ReadNumber();
	cout << "\n";
	cout << "My Ciel Funtion : " << MyCielFunction(Number);
	cout << "\n";
	cout << "C++ Ciel Function : " << ceil(Number);

}
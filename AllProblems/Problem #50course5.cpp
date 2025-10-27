#include <iostream>
using namespace std;
float ReadNumber()
{
	float Number;
	cout << "Number : \n";
	cin >> Number;
	return Number;
}
float MySqrtFunction(float Number)
{
	return pow(Number,0.5 );
}


int main()
{
	float Number = ReadNumber();
	cout << "\n";
	cout << "My Sqrt Funtion : " << MySqrtFunction(Number);
	cout << "\n";
	cout << "C++ Sqrt Function : " << sqrt(Number);

}
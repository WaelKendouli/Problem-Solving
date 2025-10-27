#include <iostream>
#include<string>
using namespace std;
enum enOpiration {sum='+',subtract='-',multiply='*',divide='/' };
int ReadaNumber(string message)
{
	int n;
	cout << message << endl;
	cin >> n;
	return n;
}
enOpiration ReadOpirator(string message2)
{
	char c = '+';
	cout << message2 << endl;
	cin >> c;
	return (enOpiration)c;

}
float Opiration(int NUM1, int NUM2, enOpiration opiration)
{
	
	switch (opiration)
	{
	case enOpiration::sum:
		return NUM1 + NUM2;
	case enOpiration::subtract:
		return NUM1 - NUM2;
	case enOpiration::multiply:
			return NUM1 * NUM2;
	case enOpiration::divide:
		return NUM1 / NUM2;
	default:
		return NUM1 + NUM2;
		break;
	}

}
int main()
{
	int number1 = ReadaNumber("First value :");
	int number2 = ReadaNumber("Second value :");
	enOpiration optype = ReadOpirator("type your opirator : ");
	cout << Opiration(number1, number2, optype);
	return 0;
	
}
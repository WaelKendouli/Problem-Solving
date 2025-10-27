#include <iostream>
#include<string>
using namespace std;
int ReadNumbers(string str1)
{
	int number1;
cout << str1 << endl;
	cin >> number1;
	return number1;
}
int SumLoop()
{
int s = 0, i=1;
int Number1;
do
{
Number1 = ReadNumbers("Number  " + to_string(i));
	if (Number1==-99)
	{
	return s;	
	}
	
	s = s + Number1;
i++;
	
} while (Number1 != -99);


}
int main()
{
	cout << "result = " << SumLoop();
	return 0;
}	
	







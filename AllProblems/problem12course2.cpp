#include <iostream>
using namespace std;
enum enMaxMin {Max=1,Min=2};
void readnumbers(int& number1,int& number2)
{
	
	cout << "Number 1 :" << endl;
		cin>>number1;
		cout << "Number 2 :" << endl;
		cin >>number2 ;
}
enMaxMin CheckMaxMin(int number1, int number2)
{
	if (number1 > number2)
		return enMaxMin::Max;
	else
		return enMaxMin::Min;
}
void printcheckresult(int number1, int number2)
{
	int Max, Min;
	if (CheckMaxMin(number1, number2) == enMaxMin::Max)
	{
		Max = number1;
		Min = number2;
		cout << "Max = " << Max<<endl;
		cout << "Min = " << Min<<endl;
	}
	else
	{
		Max = number2;
		Min = number1;
		cout << "Max = " << Max<<endl;
		cout << "Min = " << Min<<endl;
	}

}

int main()
{
	int number1, number2;
	readnumbers(number1, number2);
	printcheckresult(number1, number2);
}
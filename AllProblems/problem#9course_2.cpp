#include <iostream>
using namespace std;
void readMARKS(int& number1,int& number2,int& number3)
{

	cout<<"Number 1 : "<<endl;
	cin >> number1;
	cout<<"Number 2 : "<<endl;
	cin >> number2;
	cout << "Number 3 : " << endl;
	cin >> number3;

}
int Summing(int number1, int number2, int number3)
{
	
	return number1 + number2 + number3;
	
}
void showresults(int total)
{
	 
	cout <<"Sum = "<< total;
}

int main()
{
	int number1, number2, number3;
	readMARKS(number1, number2, number3);
	showresults(Summing(number1, number2, number3));
	return 0;
}



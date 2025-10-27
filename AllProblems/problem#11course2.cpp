#include<iostream>
using namespace std;
enum enStat{ pass=1 , fail=2};

void readMARKS(int& number1, int& number2, int& number3)

{

	cout << "Number 1 : " << endl;
	cin >> number1;
	cout << "Number 2 : " << endl;
	cin >> number2;
	cout << "Number 3 : " << endl;
	cin >> number3;

}
int Summing(int number1, int number2, int number3)
{

	return number1 + number2 + number3;

}
float cal_avreage(int number1, int number2, int number3)
{
	return (float)Summing(number1, number2, number3) / 3;
}
void showresults(float Avrage)
{

	cout << "Avrage = " << Avrage;
	if (Avrage == enStat::pass)
		cout << "\n Passed \n";
	else
		cout << "\n Failed \n";

}
enStat checkStatus(int number1,int number2,int number3)
{
	if (cal_avreage(number1, number2, number3) >= 50)
		return enStat::pass;
	else
		return enStat::fail;
};

int main()
{
	int number1, number2, number3;
	readMARKS(number1, number2, number3);
	showresults(cal_avreage(number1, number2, number3));
	
	
	return 0;
}

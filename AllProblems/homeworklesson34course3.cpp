

#include <iostream>
using namespace std;
void mysumprocuder()
{
	int a, b;
	cout<<"please enter number1  "<<endl;
	cin >> a;
	cout << "please enter number2  " << endl;
	cin >> b;
	cout << "****************************\n";
	cout << a + b;
}
int mysumfunction()
{
	int a, b;
	cout << "please enter number1  " << endl;
	cin >> a;
	cout << "please enter number2  " << endl;
	cin >> b;
	cout << "****************************\n";
	return a + b;
}
int main()
{
	//mysumprocuder();
	cout << mysumfunction() << endl;
}



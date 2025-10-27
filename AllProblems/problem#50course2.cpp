#include <iostream>
using namespace std;



int main()
{
	int c = 0 , PIN;
	cout << "Enter your PIN : " << endl;
	while (c!=3)
	{
		cin >> PIN;
		if (PIN == 1234) {
			cout << "Your balance : 7500" << endl;
			c = 3;
		}
		
		else
		{
			c++;
			cout << "try again : " << endl;
			
		}
		

	}
	
}



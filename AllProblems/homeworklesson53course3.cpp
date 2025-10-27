#include <iostream>
using namespace std;



int main()
{
	int s=0,num=0;
	for (int i = 1; i <=5; i++)
	{
		cout << "value nember " << i << " : " << endl;
		cin >> num;
		if (num >= 50);
		{
			continue;
		}
		s += num;
	}
	
	cout << "Sum = " << s << endl;
}


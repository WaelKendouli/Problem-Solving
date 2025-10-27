#include <iostream>
using namespace std;



int main()
{
	int tab[10] = { 1,2,3,45,20,88,99,77,55,5 };
	for (int i = 0; i <=10; i++)
	{
		if (tab[i] == 20)
		{
			cout << i << endl;
			break;
		}
	}
}

#include <iostream>
#include <cstdlib>

using namespace std;
int CustomRandomNumber(int from , int To)
{
	return rand() % ((To - from + 1) + from);
}


int main()
{
	srand((unsigned)time(NULL));
	//cout << rand() << endl;
	cout << CustomRandomNumber(1, 6)<<endl;
	cout << CustomRandomNumber(5, 26)<<endl;
	cout << CustomRandomNumber(11, 76)<<endl;
	cout << CustomRandomNumber(1, 10)<<endl;

	return 0;
}



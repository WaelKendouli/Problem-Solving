#include <iostream>
using namespace std;
enum enNumbertype{odd=1,even=2};

int reader()
{
	int num;
	cout << "give number : " << endl;
	cin >> num;
	return num;
}
enNumbertype checkernumber(int num)
{
	int result = num % 2;
	if (result==0)
	{
		return enNumbertype::even;
	}
	else
	{
		return enNumbertype::odd;
	}
}
void printer(enNumbertype Numbertype)
{
	if (Numbertype == enNumbertype::odd)
	{
		cout << "odd" << endl;
	}
	else
	{
		cout << "even" << endl;
	}
}

int main()
{
	printer(checkernumber(reader()));
	return 0;
}


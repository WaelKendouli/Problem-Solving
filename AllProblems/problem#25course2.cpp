#include <iostream>
using namespace std;
int ReadAge()
{
	int Age;
	cout << "Age : " << endl;
	cin >> Age;
	return Age;
}

bool ValidateAge(int from , int to ,int Age)
{
	return (Age >= from && Age <= to);
}
int loopvalidation(int from, int to)
{
	int Age = 0;
	do
	{
		Age = ReadAge();
	} while (!ValidateAge(from, to,Age));
	return Age;
}
void showingresults(int Age)
{
	if (ValidateAge(18, 45, Age))
		cout << "Valid :" << Age;
	else
		cout << "Not Valid :" << Age;
}

int main()
{
	showingresults(loopvalidation(18, 45));

}



#include <iostream>
using namespace std;


int justread()
{
	int age;
	cout << "age :" << endl;
	cin >> age;
	return age;
}
bool ValidateAge(int num,int from,int to)
{
	
		return (num >= from && num <= to);
	
}
void PrintValidation(int age)
{
	if (ValidateAge(age, 18, 45) == true)
		cout << "Valid" << endl;
	else
		cout << "Invalid" << endl;

}

int main()
{
	PrintValidation(justread());

	return 0;
}



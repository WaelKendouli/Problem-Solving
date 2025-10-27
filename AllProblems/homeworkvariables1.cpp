

#include <iostream>
using namespace std;

int main()
{
	string Name , City , Country  ;
	char Gender;
	int Age; 
	float Mounthly_sallery, Yearly_sallery ;
	bool Married;
	cout << " your name :" << endl; 
	cin >> Name;

		cout << "your city :" << endl;
		cin >> City;

		cout << "your age :" << endl;
		cin >> Age;
		cout << "your country :" << endl;
		cin >> Country;

		cout << " your gender :" << endl;
		cin >> Gender;

		cout << " are you married ( answser with 0 or 1 ) :" << endl;
		cin >> Married;
	 
		cout << " your mounthly salary :" << endl;
		cin >> Mounthly_sallery;
	 
	cout << "*************************************\n";
	cout << "Name : " << Name << endl; 
	cout << "Age : " << Age  << endl;
	cout << "City : " << City  << endl;
	cout << "Country : " << Country  << endl;
	cout << "Mounthly_salary : " << Mounthly_sallery  << endl;
	cout << "Yearly_salary : " << Mounthly_sallery * 12   << endl;
	cout << "Gender : " << Gender << endl;
	cout << "Married : " << Married  << endl;
	cout << "*************************************\n";



	return 0;
}



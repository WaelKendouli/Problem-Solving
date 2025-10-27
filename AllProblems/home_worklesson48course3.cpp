#include <iostream>
using namespace std;
struct stInfo
{
	string firstname;
	string lastname;
	int Age;
	string phone;
};
void read_one_information(stInfo& inf)
{
	cout << " first name : " << endl;
	cin >> inf.firstname;
	cout << " last name : " << endl;
	cin >> inf.lastname;
	cout << " Age : " << endl;
	cin >> inf.Age;
	cout << " phone : " << endl;
	cin >> inf.phone;
}
void show_one_information(stInfo inf)
{
	cout << "\n******************************\n";
	cout << "firstname :" << endl;
	cout << inf.firstname << endl;
	cout << "lastname :" << endl;
	cout << inf.lastname << endl;
	cout << "Age :" << endl;
	cout << inf.Age << endl;
	cout << "phone :" << endl;
	cout << inf.phone << endl;
	cout << "\n******************************\n";

}

void read_all_information(stInfo User[100],int& size)
{
	cout << "Size :" << endl;
	cin >> size;
	for(int i=0;i<=size-1;i++)
	{
	read_one_information(User[i]);

	}

}
void show_all_information(stInfo User[100], int size)
{
	for (int i = 0; i <= size-1 ; i++)
	{ 
	show_one_information(User[i]);
	
	}
}

int main()
{
int size=1;
	stInfo User[100];
	
	read_all_information(User,size);
	show_all_information(User,size);
	return 0;
}






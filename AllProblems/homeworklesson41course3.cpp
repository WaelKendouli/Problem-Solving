

#include <iostream>
using namespace std;
struct stInfo
{
	string firstname;
	string lastname;
	int Age;
	string phone;
};
void read_one_information(stInfo &inf)
{
	 cout<<" first name : "<<endl;
	 cin>>inf.firstname ;
	 cout<<" last name : "<<endl;
	 cin>>inf.lastname ;
	 cout<<" Age : "<<endl;
	 cin>> inf.Age ;
	 cout<<" phone : "<<endl;
	 cin>>inf.phone ;
}
void show_one_information(stInfo inf)
{
	cout << "\n******************************\n";
	cout<<"firstname :"<<endl;
	cout<<inf.firstname <<endl;
	cout<<"lastname :"<<endl;
	cout<<inf.lastname <<endl;
	cout<<"Age :"<<endl;
	cout<<inf.Age <<endl;
	cout<<"phone :"<<endl;
	cout<<inf.phone <<endl;
	cout << "\n******************************\n";

}

void read_all_information(stInfo User[2])
{
	
	read_one_information( User[0]);
	read_one_information(User[1]);

}
void show_all_information(stInfo User[2])
{
	show_one_information(User[0]);
	show_one_information(User[1]);
}

int main()
{
	stInfo User[2];
	read_all_information( User);
	show_all_information(User);
	return 0;
}



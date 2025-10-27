#include <iostream>
using namespace std;
struct stUserinfo
{
	int Age;
	bool hasdrivingLicence;
};
stUserinfo READINFO()
{
	stUserinfo user;
	
	cout<<"YOUR AGE :"<<endl;
	cin >> user.Age;
	cout << "DO YOU HAVE A DRIVER LICENCE ? :" << endl;
	cin >> user.hasdrivingLicence;
	return user;
}
bool checkifAccepted(stUserinfo user)
{
	return(user.Age > 21 && user.hasdrivingLicence == 1);
}
void printresults(stUserinfo user)
{
	if (checkifAccepted(user) == 1)
	{
		cout << "Hired " << endl;
	}
	else
		{
		cout << "rejected" << endl;
	}
}
int main()	
{
	printresults(READINFO());

}
#include <iostream>
using namespace std;
struct stUserinf
{
	int Age;
	bool HasDrivingLicence;
	bool Recommendation;
};
stUserinf readinfo()
{
	stUserinf user;
	cout << " YOUR AGE :" << endl;
	cin >> user.Age;
	cout << "DO YOU HAVE A DRIVING LICENCE ? :" << endl;
	cin >> user.HasDrivingLicence;
	cout << "ARE YOU RECOMMENDED ? :" << endl;
	cin >> user.Recommendation;
	return user;
}
bool CheckIfAccepted(stUserinf user)
{
	if (user.Recommendation)
	{
		return true;
	}
	else
	{
	return (user.Age > 21 && user.HasDrivingLicence == 1);

	}
}

void printresults(stUserinf user)
{
	if (CheckIfAccepted(user)==1)
	{
		cout << "\n Hired \n";
	}
	else
	{
		cout << "\n rejected \n";
	}
}
int main()
{
	printresults(readinfo());

	return 0;
}


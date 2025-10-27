#include <iostream>
using namespace std;
string ReadPassword(string str)
{
	
		cout << str << endl;
		cin >> str;
	return str;
}
bool ShowTrialPassword( string OriginalPassword )
{

	string Password;

	int c = 0;
	
		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90 ; j++)
			{

				for (int k = 65; k <= 90 ; k++)
				{
					c++;
					if (Password==OriginalPassword)
					{
						cout << "Password is :" << Password << endl;
						cout << "Found after " << c << " Trial(s)";
						return true;
					}
					Password = "";

					Password = Password + char(i);
					Password = Password + char(j);
					Password = Password + char(k);
					
					cout << "Trial(" << c << ")" << " : " 
						<< char(i) << char(j) << char(k) << endl;
					

				}

			}


		}

	
	return false;
}


int main()
{
	ShowTrialPassword(ReadPassword("Enter a Password (all capital) :"));
	
}


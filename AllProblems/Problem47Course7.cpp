#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
struct stClientInfo
{
	string AcountNumber = "";
	string PinCode;
	string Name = "";
	string Phone = "";
	double AcountBalance ;
};
stClientInfo ReadClinetInfo()
{
	stClientInfo ClientInfo;
	cout << "\n\n Enter Client data :\n\n";
	cout << "Account Number :" << endl;
	getline(cin >> ws, ClientInfo.AcountNumber);
	cout << "Name : " << endl;
	getline(cin, ClientInfo.Name);
	cout << "Phone" << endl;
	getline(cin, ClientInfo.Phone);
	cout << "PIN Code :" << endl;
	getline(cin, ClientInfo.PinCode);
	cout << "Account Balance : " << endl;
	cin >> ClientInfo.AcountBalance;

	return ClientInfo;
}
string TurnDataToOneLine(stClientInfo ClientInfo, string Delim)
{
	string StrClientInfo = "";
	StrClientInfo += ClientInfo.AcountNumber + Delim;
	StrClientInfo += ClientInfo.PinCode + Delim;
	StrClientInfo += ClientInfo.Name + Delim;
	StrClientInfo += ClientInfo.Phone + Delim;
	StrClientInfo += to_string(ClientInfo.AcountBalance);

	return StrClientInfo;
}



void StoreRecordToFile(string str,string FileName)
{
	fstream ClientFile; ;
	ClientFile.open(FileName, ios::out | ios::app);
	if (ClientFile.is_open())
	{
		 
			ClientFile << str<<endl;
		
		ClientFile.close();
	}
}
void AddClient()
{
stClientInfo ClientInfo;
	string str;
	ClientInfo = ReadClinetInfo();
	
		str = TurnDataToOneLine(ClientInfo, "#//#");
		StoreRecordToFile(str,"ClientInfo.txt");
}
void AddNewClients()
{
	char Choice = 'y';
	do
	{
		system("cls");
		cout << "Adding new Client :\n\n";
		AddClient();
		cout << "Client Added Succesfuly , do you want to add more ? (y/n) :";
		cin >> Choice;
	} while (toupper(Choice) == 'Y');
}
int main()
{
	AddNewClients();
    return 0;
}


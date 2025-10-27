#include <iostream>
#include<vector>
#include<string>
using namespace std;

struct stClientInfo
{
	string AcountNumber = "";
	string PinCode;
	string Name="";
	string Phone="";
	float AcountBalance=0;
};
stClientInfo ReadClinetInfo()
{
	stClientInfo ClientInfo;
	cout << "\n\n Enter Client data :\n\n";
	cout<<"Account Number :"<<endl;
	getline(cin>>ws, ClientInfo.AcountNumber);
	cout<<"Name : "<<endl;
	getline(cin, ClientInfo.Name);
	cout<<"Phone"<<endl;
	getline(cin, ClientInfo.Phone);
	cout<<"PIN Code :"<<endl;
	getline(cin, ClientInfo.PinCode);
	cout<<"Account Balance : "<<endl;
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
	StrClientInfo += to_string(ClientInfo.AcountBalance) ;

	return StrClientInfo;
}
int main()
{
	stClientInfo ClientInfo;
	ClientInfo = ReadClinetInfo();

	cout << "Client reord Saving is :\n\n";
	cout<<TurnDataToOneLine(ClientInfo, "#//");
}



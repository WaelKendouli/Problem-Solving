#include <iostream>
#include<string>
#include<vector>

using namespace std;

struct stClientInfo
{
	string AcountNumber = "";
	string PinCode;
	string Name = "";
	string Phone = "";
	string AcountBalance = "";
};
vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}


stClientInfo ConvertRecordToData(string str )
{
	stClientInfo ClientInfo;
	vector<string> vString;
	vString = SplitString(str, "#//#");
	ClientInfo.AcountNumber = vString[0];
	ClientInfo.PinCode = vString[1];
	ClientInfo.Name = vString[2];
	ClientInfo.Phone = vString[3];
	ClientInfo.AcountBalance = vString[4];

	return ClientInfo;
}
void PrintClientData(stClientInfo ClientInfo)
{
	cout << "Account Number :" ;
	cout<< ClientInfo.AcountNumber;
	cout << "Name : " ;
	cout<< ClientInfo.Name;
	cout << "Phone" ;
	cout<< ClientInfo.Phone;
	cout << "PIN Code :" << ClientInfo.PinCode; 
	cout << "Account Balance : " << ClientInfo.AcountBalance;
}
int main()
{
	string str = "A102#//#1234#//#Mohammed Abu-hadhoud#//#072356486#//#5700";
	cout << "Client record : " << endl;
	cout << str << endl;
	stClientInfo ClientInfo=ConvertRecordToData(str);
	
	cout << "\n\nThe Following is the extracted client record : \n\n";
	PrintClientData(ClientInfo);
}



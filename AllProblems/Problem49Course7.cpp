#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


const string fileName = "ClientData.txt";
struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};
string ReadAccountNumber()
{
    string UserInput;
    cout << "enter Account Number :" << endl;
    getline(cin, UserInput);
    return UserInput;
}
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
sClient ConvertLinetoRecord(string str)
{
    vector<string> vClientData;
    sClient Client;
    vClientData = SplitString(str, "#//#");

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to

    return Client;
}
vector<sClient> LoadClientDataFromFile(string filename)
{
    fstream ClientFile;
    vector <sClient> vClient;
    ClientFile.open(filename, ios::out | ios::in);
    if (ClientFile.is_open())
    {
        string fileLine;
        sClient client;
        while (getline(ClientFile, fileLine))
        {
            client = ConvertLinetoRecord(fileLine);
            vClient.push_back(client);
        }
        ClientFile.close();
    }
    return vClient;
}
bool FindClientAccount(string ClientAccountNumber, sClient& Client)
{
    vector<sClient> vClientData = LoadClientDataFromFile(fileName);
    for (sClient& line : vClientData)
    {
        if (line.AccountNumber == ClientAccountNumber)
        {
            Client = line;
            return true;
        }
    }
    return false;
}
void ShowFoundData(sClient Client)
{
    cout << "The following are the client details : \n";
    cout << "Account Number ";
    cout << Client.AccountNumber << endl;
    cout << "\nName :";
    cout << Client.Name;
    cout << "\nPhone :" << endl;
    cout << Client.Phone << endl;
    cout << "\nPinCode :";
    cout << Client.PinCode << endl;
    cout << "\nAccount Balance : ";
    cout << Client.AccountBalance << endl;
}


int main()
{

    string AccountNumber = ReadAccountNumber();
    sClient Client;
    if (FindClientAccount(AccountNumber, Client) == true)
    {
        ShowFoundData(Client);
    }
    else
    {
        cout << "Client with account number ( " << AccountNumber << " ) not fournd\n";
    }

    return 0;
}




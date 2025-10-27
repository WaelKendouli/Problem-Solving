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
    bool MarkForDelete = false;
    bool MarkForUpdate = false;
};
void CreateFile()
{
    fstream ClientFile;
    ClientFile.open(fileName, ios::out);
    if (ClientFile.is_open())
    {

        ClientFile.close();
    }
}
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
vector<sClient> LoadClientDataFromFile(string fileName)
{
    fstream ClientFile;
    vector <sClient> vClient;
    ClientFile.open(fileName, ios::in);
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
string ConvertDataToLine(sClient Client, string delim = "#//#")
{
    string FileLine;
    FileLine = Client.AccountNumber + delim;
    FileLine = Client.Name + delim;
    FileLine = Client.Phone + delim;
    FileLine = Client.PinCode + delim;
    FileLine = to_string(Client.AccountBalance);

    return FileLine;
}
vector <string> SaveFileContentToVector(string fileName)
{
    fstream ClientFile;
    vector <string> vFileContent;
    ClientFile.open(fileName, ios::out | ios::app);
    if (ClientFile.is_open())
    {
        string Line;
        while (getline(ClientFile, Line))
        {
            vFileContent.push_back(Line);
        }

        ClientFile.close();
    }
    return vFileContent;
}


bool FindClientAccount(string ClientAccountNumber, vector<sClient> vClientData, sClient& Client)
{

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
sClient ReadUpdatedData(string AccountNumber)
{
    sClient Client;
    Client.AccountNumber = AccountNumber;
    cout << "\nName :";
    getline(cin>>ws ,Client.Name);
    cout << "\nPhone :" << endl;
    getline(cin, Client.Phone);
    cout << "\nPinCode :";
    getline(cin, Client.PinCode);
    cout << "\nAccount Balance : ";
    cin >> Client.AccountBalance;
    return Client;
}


vector<sClient> SaveClientsDataToFile(string fileName, vector<sClient>& vClientData)
{
    fstream ClientFile;
    ClientFile.open(fileName, ios::out);
    if (ClientFile.is_open())
    {
        string strLine;
        for (sClient Line : vClientData)
        {
            if (Line.MarkForUpdate == false)
            {
                strLine = ConvertDataToLine(Line);
                ClientFile << strLine << endl;
           }
              
        }
        ClientFile.close();
    }
    return vClientData;
}
bool UpdateClientFromFile(string AccountNumber, vector<sClient>& vClientData)
{
    sClient Client;
    char UserChoice = 'n';
    if (FindClientAccount(AccountNumber, vClientData, Client) == true)
    {
        ShowFoundData(Client);

        cout << "\n\n Do you want to Update this user's informations ? y/n \n\n";
        cin >> UserChoice;
        if (tolower(UserChoice) == 'y')
        {
            for (sClient& Line : vClientData)
            {
                if (Line.AccountNumber == AccountNumber)
                {
                    Line = ReadUpdatedData(AccountNumber);
                    break;
                }
            }
            SaveClientsDataToFile(fileName, vClientData);
            //refresh clients
            
            cout << "Your record has been updated succesfuly";
            return true;
        }
    }
    else
    {
        cout << "Client with account number ( " << AccountNumber << " ) not fournd\n";
        return false;
    }
}
int main()
{
   
    
   vector<sClient> vClientData = LoadClientDataFromFile(fileName);
    string AccountNumber = ReadAccountNumber();

    UpdateClientFromFile(AccountNumber, vClientData);

    return 0;
}

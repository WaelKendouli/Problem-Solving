#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const string ClientsFileName = "ATM Clients.txt";

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};
enum enATM_MenueOptions {
    eQuickWithdraw = 1, eNormalWithdraw = 2,
    eDeposit = 3, eCheckBalance = 4, eLogout = 5,
  
};
enum enQuickWithdraw {Withdraw20=1, Withdraw50 = 2,
    Withdraw100 = 3, Withdraw200 = 4, Withdraw400 = 5, Withdraw600 = 6
    , Withdraw800 = 7, Withdraw1000 = 8,Exit=9};
void ShowATM_MainMenu(sClient&);
void ShowQuickWithdrawMenu(sClient&);
vector<string> SplitString(string S1, string Delim = "#//#")
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
        S1.erase(0, pos + Delim.length()); /* erase() until
        positon and move to next word. */
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}
sClient ConvertLinetoRecord(string Line, string Seperator =
    "#//#")
{
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to

    return Client;
}
string ConvertRecordToLine(sClient Client, string Seperator =
    "#//#")
{
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

bool ClientExistsByAccountNumber(string AccountNumber, string
    FileName)
{
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode
    if (MyFile.is_open())
    {
        string Line;
        sClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return false;
}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode
    if (MyFile.is_open())
    {
        string Line;
        sClient Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

sClient ReadClientInfo()
{
    sClient Client;
    cout << "\nEnter Account Number :";
    getline(cin >> ws, Client.AccountNumber);
    cout << "\nEnter PIN code  :";
    getline(cin >> ws, Client.PinCode);
    return Client;
}

bool FindClientByAccountNumber(string AccountNumber, vector
    <sClient> vClients, sClient& Client)
{
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

vector <sClient> SaveCleintsDataToFile(string FileName, vector
    <sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite
    string DataLine;
    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for

                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

void RefreshClientsDataToFile(string FileName, sClient& Client)
{
    fstream MyFile;
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    MyFile.open(FileName, ios::out);//overwrite
    string DataLine;
    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (C.AccountNumber == Client.AccountNumber)
            {
                //we only write records that are not marked for
               
                DataLine = ConvertRecordToLine(Client);
                MyFile << DataLine << endl;
            }
            else
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    
}
short PickOption(string str)
{
    short Option;
    cout << str;
    cin >> Option;
    return Option;
}
bool IsClientInputCorrect(sClient& Client)
{
    vector <sClient> vClient = LoadCleintsDataFromFile(ClientsFileName);

    for (sClient& C : vClient)
    {
        if (C.AccountNumber == Client.AccountNumber && C.PinCode == Client.PinCode)
        {
            Client = C;
            return true;
        }

    }
    return false;
}


void Login()
{
    sClient Client = ReadClientInfo();
    while (IsClientInputCorrect(Client) == false)
    {
        cout << "Invalid UserName/Password \n";
        Client = ReadClientInfo();
    }
    ShowATM_MainMenu(Client);
}
void LogInScreen()
{
    system("cls");
    cout << "----------------------------------\n";
    cout << "\t Login Screen\n";
    cout << "----------------------------------\n";
    Login();
}

bool IsClientSure()
{
    char choice;
    cout << "\nAre you sure you want to perform this  transaction Y/N?\n";
    cin >> choice;
    return (tolower(choice) == 'y' ? true : false);
}
void PerformQuickWithdrawAction(enQuickWithdraw Options,sClient& Client)
{
    switch (Options)
    {
    case Withdraw20:
        if (Client.AccountBalance>20)
        {
            if (IsClientSure() == true)
            {
                Client.AccountNumber = Client.AccountBalance - 20;

                cout << "Done Succesfully , your account balance is : " << Client.AccountBalance;
            }
        }
        else
        {
            cout << "\namount excedes your balance , make another choice \n";
            ShowQuickWithdrawMenu(Client);
        }
        break;
    case Withdraw50:
        if (Client.AccountBalance > 50)
        {
            if (IsClientSure() == true)
            {
                Client.AccountBalance = Client.AccountBalance - 50;

                cout << "Done Succesfully , your account balance is : " << Client.AccountBalance;
            }
        }
        else
        {
            cout << "\namount excedes your balance , make another choice \n";
            ShowQuickWithdrawMenu(Client);
        }
        break;
    case Withdraw100:
        if (Client.AccountBalance > 100)
        {
            if (IsClientSure() == true)
            {
                Client.AccountBalance = Client.AccountBalance - 100;

                cout << "Done Succesfully , your account balance is : " << Client.AccountBalance;
            }
        }
        else
        {
            cout << "\namount excedes your balance , make another choice \n";
            ShowQuickWithdrawMenu(Client);
        }
        break;
    case Withdraw200:
        if (Client.AccountBalance > 200)
        {
            if (IsClientSure() == true)
            {
                Client.AccountBalance = Client.AccountBalance - 200;

                cout << "Done Succesfully , your account balance is : " << Client.AccountBalance;
            }
        }
        else
        {
            cout << "\namount excedes your balance , make another choice \n";
            ShowQuickWithdrawMenu(Client);
        }
        break;
    case Withdraw400:
        if (Client.AccountBalance > 400)
        {
            if (IsClientSure() == true)
            {
                Client.AccountBalance = Client.AccountBalance - 400;

                cout << "Done Succesfully , your account balance is : " << Client.AccountBalance;
            }
        }
        else
        {
            cout << "\namount excedes your balance , make another choice \n";
            ShowQuickWithdrawMenu(Client);
        }
        break;
    case Withdraw600:
        if (Client.AccountBalance > 600)
        {
            if (IsClientSure() == true)
            {
                Client.AccountBalance = Client.AccountBalance - 600;

                cout << "Done Succesfully , your account balance is : " << Client.AccountBalance;
            }
        }
        else
        {
            cout << "\namount excedes your balance , make another choice \n";
            ShowQuickWithdrawMenu(Client);
        }
        break;
    case Withdraw800:
        if (Client.AccountBalance > 800)
        {
            if (IsClientSure() == true)
            {
                Client.AccountBalance = Client.AccountBalance - 800;

                cout << "Done Succesfully , your account balance is : " << Client.AccountBalance;
            }
        }
        else
        {
            cout << "\namount excedes your balance , make another choice \n";
            ShowQuickWithdrawMenu(Client);
        }
        break;
    case Withdraw1000:
        if (Client.AccountBalance > 1000)
        {
            if (IsClientSure() == true)
            {
                Client.AccountBalance = Client.AccountBalance - 1000;

                cout << "Done Succesfully , your account balance is : " << Client.AccountBalance;
            }
        }
        else
        {
            cout << "\namount excedes your balance , make another choice \n";
            ShowQuickWithdrawMenu(Client);
        }
        break;
    case Exit:
        ShowATM_MainMenu(Client);
        break;
    
    }
}
void ShowQuickWithdrawMenu(sClient& Client)
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\t Quick Withdraw \n";
    cout << "===========================================\n";
    cout << "\t[1] 20. \t [2] 50.\n";
    cout << "\t[3] 100. \t [4] 200.\n";
    cout << "\t[5] 400. \t [6] 600.\n";
    cout << "\t[7] 800. \t [8] 1000.\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
    cout << "\nYour account Balance : " << Client.AccountBalance << endl;
    PerformQuickWithdrawAction((enQuickWithdraw)PickOption("\nchoose number from 1 to 9"), Client);
}

void NormalWithdraw(sClient& Client)
{
    short AmountOfMoney = 0;
    cout << "\nEnter an amount of multiple of 5's : ";
    cin >> AmountOfMoney;
    while (AmountOfMoney%5!=0||AmountOfMoney>Client.AccountBalance)
    {
        if (AmountOfMoney > Client.AccountBalance)
        {
            cout << "\nAmount exedes your balance , make another choice \n";
        }
        cout << "\nEnter an amount of multiple of 5's : ";
        cin >> AmountOfMoney;
    }
    if (IsClientSure() == true)
    {
        Client.AccountBalance = Client.AccountBalance - AmountOfMoney;
        cout << "Done Successfully , your account balance is : " << Client.AccountBalance;
    }
   
}

void Deposit(sClient& Client)
{
   short AmountOfMoney = 0;
    cout << "\nEnter an amount of multiple of 5's : ";
    cin >> AmountOfMoney;
   
    if (IsClientSure() == true)
    {
        Client.AccountBalance = Client.AccountBalance + AmountOfMoney;
        cout << "Done Successfully , your account balance is : " << Client.AccountBalance;
    }
}
void DepositScreen(sClient& Client)
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\t Normal Withdraw \n";
    cout << "===========================================\n";
    Deposit(Client);

}

void ShowNormalWithdrawScreen(sClient& Client)
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\t Normal Withdraw \n";
    cout << "===========================================\n";
    NormalWithdraw(Client);
}

void ShowCheckBalanceScreen(sClient& Client)
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\t Check Balance \n";
    cout << "===========================================\n";
    cout << "Your account Balance : " << Client.AccountBalance << endl;
}

void PerformATM_MenuScreen(enATM_MenueOptions MenuOptions, sClient& Client)
{
    switch (MenuOptions)
    {
    case eQuickWithdraw:
        ShowQuickWithdrawMenu(Client);
        system("pause>0");
        ShowATM_MainMenu(Client);
        break;
    case eNormalWithdraw:
        ShowNormalWithdrawScreen(Client);
        system("pause>0");
        ShowATM_MainMenu(Client);
        break;
    case eDeposit:
        DepositScreen(Client);
        system("pause>0");
        ShowATM_MainMenu(Client);
        break;
    case eCheckBalance:
        ShowCheckBalanceScreen(Client);
        system("pause>0");
        ShowATM_MainMenu(Client);
        break;
    case eLogout:
        RefreshClientsDataToFile(ClientsFileName, Client);
        LogInScreen();
        break;

    }

}
void ShowATM_MainMenu(sClient& Client)
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\t ATM Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick withdraw.\n";
    cout << "\t[2] Normal withdraw.\n";
    cout << "\t[3] Deposite \n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Log out.\n";
    cout << "===========================================\n";
    PerformATM_MenuScreen((enATM_MenueOptions)PickOption("Chose number from 1 to 5 : "), Client);
}
int main()
{
    LogInScreen();
	system("pause");
}



#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct stDate
{
   short Day;
   short Month;
   short Year;
};

string ReadDateStirng()
{
    string str;
    getline(cin,str);
    return str;
}
vector<string> SplitString(string S1, string Delim="/")
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

stDate ConvertStringToData(string str)
{
    stDate Date;
    vector <string> vString;
    vString = SplitString(str);
    Date.Day = stoi(vString[0]);
    Date.Month= stoi(vString[1]);
    Date.Year = stoi(vString[2]);

    return Date;
}
void ShowDate(stDate Date)
{
    cout << " Day : " << Date.Day << endl;
    cout << " Month : " << Date.Month << endl;
    cout << " Year : " << Date.Year << endl;
}

string ConvertDateToString(stDate Date)
{

    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}
int main()
{
    stDate Date;
    string str;
    cout << " Please Enter Date dd/mm/yyy ? \n";
    str = ReadDateStirng();
    Date = ConvertStringToData(str);
    ShowDate(Date);

    cout << "You entered : " << ConvertDateToString(Date);
    system("pause>0");
}



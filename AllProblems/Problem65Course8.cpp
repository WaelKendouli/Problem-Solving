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
    getline(cin, str);
    return str;
}
vector<string> SplitString(string S1, string Delim = "/")
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
    Date.Month = stoi(vString[1]);
    Date.Year = stoi(vString[2]);

    return Date;
}
void ShowDate(stDate Date)
{
    cout << " Day : " << Date.Day << endl;
    cout << " Month : " << Date.Month << endl;
    cout << " Year : " << Date.Year << endl;
}

string ReplaceWordInString(string S1, string StringToReplace,
    string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(),
            sRepalceTo);
        pos = S1.find(StringToReplace);//find next
    }
    return S1;
}

string ConvertDateToString(stDate Date)
{

    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

string FormatDate(stDate Date,string DateFormat="dd/mm/yyyy")
{
    
    string FormattedDateString = "";
    FormattedDateString = ReplaceWordInString(DateFormat,"dd", to_string(Date.Day) );
    FormattedDateString = ReplaceWordInString(FormattedDateString ,"mm" , to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString,"yyyy" ,to_string(Date.Year) );

    return FormattedDateString;

}
int main()
{
    stDate Date;
    string str;
    cout << " Please Enter Date dd/mm/yyy ? \n";
    str = ReadDateStirng();
    cout << "\n";
   
    Date = ConvertStringToData(str);
   
    cout << FormatDate(Date) << "\n\n";
    cout<< FormatDate(Date, "mm/dd/yyyy") <<"\n\n";
    cout<< FormatDate(Date, "mm-dd-yyyy") <<"\n\n";
    cout<< FormatDate(Date, "dd-mm-yyyy") <<"\n\n";
    cout<< FormatDate(Date, "Day:dd  ,   Month:mm  ,  Year:yyyy ") <<"\n\n";

    

    system("pause>0");
}

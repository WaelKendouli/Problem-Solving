#include <iostream>
#include<string>
#include<vector>
using namespace std;

string ReadString()
{
	string str;
	cout << "Enter Your String ? :" << endl;
	getline(cin, str);
	return str;
}
string JoinString(vector<string> vString, string delim)
{
	string S = "";
	for (string& line : vString)
	{
		S = S + line + delim;
	}
	S = S.substr(0, S.length() - delim.length() - 1);
	return S;
}

vector<string> SplitString(string str, string delim)
{
	vector<string> vString;
	string sWord;
	short pos = 0;
	while ((pos = str.find(delim)) != std::string::npos)
	{
		sWord = str.substr(0, pos);
		if (sWord != delim)
		{
			vString.push_back(sWord);
		}
		str.erase(0, pos + delim.length());
	}
	if (str != " ")
	{
		vString.push_back(str);
	}
	return vString;
}
string UpperCaseToLowerCaseWord(string Word)
{
	for (short i = 0; i < Word.length(); i++)
	{
		if ((short)Word[i] >= 65 && (short)Word[i] <= 90)
		{
			Word[i] = tolower(Word[i]);
		}
	}
	return Word;
}
string ReplaceWordInString(vector<string> vString, string str, string Word, string ReplacingWord,bool CaseSensetiv=true)
{
	vString = SplitString(str, " ");
	for (string& Line : vString)
	{
		if (CaseSensetiv == true)
		{
			if (Line == Word)
			{
				Line = ReplacingWord;

			}
		}
		else
		{
			if (UpperCaseToLowerCaseWord(Line) == UpperCaseToLowerCaseWord(Word))
			{
				Line = ReplacingWord;

			}

		}
			
		
	}

	return JoinString(vString," ");
}


int main()
{
	string str;
	str = ReadString();
	cout << "\n\nString original  : \n\n";
	cout << str << endl;
	vector<string> vStirng;
	cout << "\n\n Replaced With match case : \n\n";
	cout<<ReplaceWordInString(vStirng,str , "Algeria", "Palestine");
	
	cout << "\n\n Replaced With no match case : \n\n";
	cout << ReplaceWordInString(vStirng, str, "Algeria", "Palestine", false)<<endl;
	 // i Love Algeria , Algeria is a Beautiful country 
	 // i Love algeria , algeria is a Beautiful country 
}

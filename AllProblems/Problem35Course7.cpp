#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
	string str;
	cout << "Enter Your String ? :" << endl;
	getline(cin, str);
	return str;
}


void WordsInString(string str)
{
	string Delemiter = " ";
	cout << "Your Words In String are :\n";
	short pos = 0;
	string Word;

	while ((pos = str.find(Delemiter)) != std::string::npos) //Always Remember Two Bows
	{
		Word = str.substr(0, pos);
		if (Word != "")
		{
			cout << Word << endl;
		}
		str.erase(0, pos + Delemiter.length());
	}
	if (str!="")
	{
		cout << str << endl;
	}
}
int main()
{
	WordsInString(ReadString());
	

}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	string str;
	cout << "Enter Your String ? :" << endl;
	getline(cin, str);
	return str;
}
vector <string> SplitString(string S, string delimeter)
{
	vector <string> vStringVector;
	short pos = 0;
	string word;
	while ((pos = S.find(delimeter)) != std::string::npos)
	{
		word = S.substr(0, pos);
		if (word != delimeter)
		{
			vStringVector.push_back(word);
		}
		S.erase(0, pos + delimeter.length());
	}
	if (S != "")
	{
		vStringVector.push_back(S);
	}
	return vStringVector;
}


string ReverseString(string str)
{
	vector <string> vStringVector;
	vStringVector = SplitString(str," ");
	string S = "";
	vector<string>::iterator iter = vStringVector.end();
	while (iter != vStringVector.begin())
	{
		--iter;
		S += *iter + " ";
	}
	S = S.substr(0, S.length() - 1);
	return S;
}
int main()
{
	string S; 
	S = ReadString();
	cout << "Reversed String : \n";
	cout<<ReverseString(S);
}
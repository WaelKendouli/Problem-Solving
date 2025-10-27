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
	while ((pos=S.find(delimeter))!=std::string::npos)
	{
		word = S.substr(0, pos);
		if (word != delimeter)
		{
			vStringVector.push_back(word);
		}
		S.erase(0 ,pos + delimeter.length());
	}
	if (S!="")
	{
		vStringVector.push_back(S);
	}
	return vStringVector;
}

int main()
{
	vector <string> vStringVector;

	string str;
	
	vStringVector = SplitString(ReadString(), " ");
	cout << "Tokens = " << vStringVector.size()<<endl;
	for (string& s : vStringVector)
	{
		cout << s << endl;
	}
}



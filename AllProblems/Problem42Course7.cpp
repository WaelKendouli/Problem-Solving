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
string ReplaceWordInAStringWithBuiltInFunction(string str, string Wordtoreplace, string ReplacedTo)
{
	
	short pos = str.find(Wordtoreplace);
	while (pos!=std::string::npos)
	{
		str = str.replace(pos, Wordtoreplace.length(), ReplacedTo);
		pos = str.find(Wordtoreplace);
	}
	return str;
}
int main()
{
	string str;
	str = ReadString();
	cout << "String original  : \n";
	cout << str << endl;
	cout << "String After Replacing   : \n";
	cout << ReplaceWordInAStringWithBuiltInFunction(str, "Algeria", "Bosnia");
}
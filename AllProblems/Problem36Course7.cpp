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
short int CountWordsInString(string S1)
{
	string delimeter = " ";
	string Word;
	short pos = 0;
	short counter = 0;
	while ((pos=S1.find(delimeter))!=std::string::npos)
	{
		Word = S1.substr(0, pos);
		if (Word!="")
		{
			counter++;
		}
		S1.erase(0, pos + delimeter.length());
	}
	if (S1 != "")
	{
		counter++;
	}
	return counter;
}
int main()
{
	cout << "the Number of Words in Your String is  : " << CountWordsInString(ReadString())<< endl;
} 
	



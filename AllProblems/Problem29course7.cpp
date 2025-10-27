

#include <iostream>
#include <string>
using namespace std;
enum enWhatToCount{ CapitalLetter = 0 , SmallLetter=1
};
string ReadString()
{
	string str;
	cout << "Enter Your String ? :" << endl;
	getline(cin, str);
	return str;
}
short int CountLetters(string str,enWhatToCount TypeOfCount)
{
	short int Counter = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]) &&TypeOfCount==enWhatToCount::CapitalLetter)
			Counter++;
		if (islower(str[i]) && TypeOfCount == enWhatToCount::SmallLetter)
			Counter++;
	}
	return Counter;
}

void PrintResults(string str)
{
	cout << "String length : " << str.length()<< endl;
	cout << "Capital letter counter : " << CountLetters(str,enWhatToCount::CapitalLetter) << endl;
	cout << "Small letter counter : " << CountLetters(str, enWhatToCount::SmallLetter) << endl;
}

int main()
{
	string str = ReadString();
	
	PrintResults(str);
}

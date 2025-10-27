#include <iostream>
#include<string>
using namespace std;


char ReadChar()
{
	char Ch;
	cout << "Enter Your Charecter  ? :" << endl;
	cin >> Ch;
	return Ch;
}
bool CheckIfVowel(char ch)
{
	 
		ch = tolower(ch);
	
	return ((ch == 'a') || (ch == 'i') || (ch == 'e') || (ch == 'u') || (ch == 'o'));

}
void PrintResult(bool Result , char ch)
{
	if(Result==true)
	{
		cout << "Yes letter " << ch << " is a vowel";
	}
	else
		cout << "No letter " << ch << " is a Not vowel";
}
int main()
{
	char ch = ReadChar();
	PrintResult(CheckIfVowel(ch), ch);
}

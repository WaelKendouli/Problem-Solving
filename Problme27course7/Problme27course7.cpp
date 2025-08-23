#include <iostream>
#include<string>
using namespace std;
char ReadCharecter()
{
	char  charecter;
	cout << "Enter Your Charecter ? :" << endl;
	cin >> charecter;
	return charecter;
}

char InvertCharecter(char Charecter)
{
	return isupper(Charecter) ? tolower(Charecter) : toupper(Charecter);
}
int main()
{
	char c = ReadCharecter();
	c = InvertCharecter(c);
	cout << "charecter after inverting :\n";
	cout << c << endl;
	return 0;
}



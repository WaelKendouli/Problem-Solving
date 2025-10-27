#include <iostream>
#include <cstdlib>
using namespace std;
enum enRandomizecharecter { SmallLetter = 1, CapitalLetter = 2, 
	SpecialCharecter = 3, Digit=4 };

int ReadNumber(string str)
{
	int Number;
	do
	{
		cout << str << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}
int CustomRandomNumber(int To , int From)
{
	return rand() % ((To - From + 1) + From);
}
char RandomCharacter(enRandomizecharecter charecter)
{
	switch (charecter)
	{
	case SmallLetter:
		return char(CustomRandomNumber(97, 122));
		break;
	case CapitalLetter:
		return char(CustomRandomNumber(65, 90));
		break;
	case SpecialCharecter:
		return char(CustomRandomNumber(32, 47));
		break;
	case Digit:
		return char(CustomRandomNumber(48, 57));
		break;
	default:SmallLetter;
		break;
	}

}
string GenrateWord(short LengthKey )
{
	string Word;
	for (int i = 1; i <= LengthKey ; i++)
	{
		Word = Word + RandomCharacter(enRandomizecharecter::CapitalLetter);
	}
	return Word;
}


string GenrateKey()
{
	string key;
	key = key + GenrateWord(4)+"-";
	key = key + GenrateWord(4) + "-";
	key = key + GenrateWord(4) + "-";
	key = key + GenrateWord(4) ;
	return key;
}
void GenrateKeys(short NumberOfKeys)
{
	for (int i = 1; i <= NumberOfKeys; i++)
	{
		cout <<"key  "<< "[" << i << "]" << " : "<<endl;
		GenrateKey();

	}

}

int main()
{
	srand((unsigned)time(NULL));

	GenrateKeys(ReadNumber("Number of keys :"));
	return 0;
}



#include <iostream>
#include<cstdlib>
using namespace std;
enum enRandomizecharecter { SmallLetter = 1, CapitalLetter = 2, SpecialCharecter = 3, Digit };
int ReadNumber(string str)
{
	int Number;
	do
	{
		cout << str << endl;
		cin >> Number;

	} while (Number<=0);
	return Number;
}



int CustomRandomNumber(int from, int To)
{
	return rand() % ((To - from + 1) + from);
}
char RandomCharacter(enRandomizecharecter charecterType)
{
	switch (charecterType)
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
string GenerateWord(enRandomizecharecter charecter , short length)
{
	string word;
	for (int i = 0; i < length; i++)
	{
		word = word + RandomCharacter(charecter);
	}
	return word;
}
string GenerateKey()
{
	
	string key="";
	key = key + GenerateWord(enRandomizecharecter::CapitalLetter, 4) + "-";
	key = key + GenerateWord(enRandomizecharecter::CapitalLetter, 4) + "-";
	key = key + GenerateWord(enRandomizecharecter::CapitalLetter, 4) + "-";
	key = key + GenerateWord(enRandomizecharecter::CapitalLetter, 4) ;
	return key;
}
void GenratekeyArrays(string arr[100],int& NumberOfArrays)
{
	
	for (int i = 0; i <= NumberOfArrays-1 ; i++)
	{
		arr[i] = GenerateKey();
		
	}

}
void PrintArrayWithKeys(string arr[100], int NumberOfArray)
{
	for (int i = 0; i < NumberOfArray; i++)
	{
		cout << "Array [" << i << "] : ";
		cout << arr[i];
		cout << "\n";
	}
	
}
int main()
{
	int NumberOfArrays = ReadNumber("Number of Arrays :");
	string arr[100];
	GenratekeyArrays(arr, NumberOfArrays);
	PrintArrayWithKeys(arr, NumberOfArrays);
}



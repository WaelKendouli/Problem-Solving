#include <iostream>
#include <cstdlib>
using namespace std;
enum enRandomizecharecter {SmallLetter=1,CapitalLetter=2,SpecialCharecter=3,Digit };
int CustomRandomNumber(int from, int To)
{
	return rand() % ((To - from + 1) + from);
}
char RandomCharacter(enRandomizecharecter charecter )
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

int main()
{
	srand((unsigned)time(NULL));
	cout << RandomCharacter(enRandomizecharecter::Digit) << endl;
	cout << RandomCharacter(enRandomizecharecter::SmallLetter) << endl;
	cout << RandomCharacter(enRandomizecharecter::SpecialCharecter) << endl;
	cout << RandomCharacter(enRandomizecharecter::CapitalLetter) << endl;

	return 0;
}



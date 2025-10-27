#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;
int RandomNumber(short int From, short int To)
{
	return  rand() % ((To - From + 1) + From);
}

void FillMatrixWithRandomNumbers(short int RandomMatrix[3][3])
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			RandomMatrix[i][j] = RandomNumber(1, 10);

		}

	}

}
short int ReadNumber(string str)
{
	short int Number;
	cout << str << endl;
	cin >> Number;
	return Number;
}
bool IsNumberExist(short int Matrix[3][3], short int Row, short int Col, short int UserNumber)
{

	
	for (short i = 0; i < Row; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			if (Matrix[i][j] == UserNumber)
			{
				return true;
			}

		}

	}
	return false;
}

string ShowResult(bool Result)
{
	if (Result == true)
		return "\nYes,Number is there";
	else
		return "\nNo,Number is not there\n";
}

void PrintRandomMatrix(short int RandomMatrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("      %0*d", 2, RandomMatrix[i][j]);
		}
		cout << "\n";
	}
}
int main()
{
	srand((unsigned)time(NULL));
	short int Matrix[3][3];
	FillMatrixWithRandomNumbers(Matrix);
	cout << "The following is a 3 x 3 Matrix :" << endl;
	PrintRandomMatrix(Matrix);
	short int UserNumber = ReadNumber("Please enter the number to look for in matrix\n");
	cout << ShowResult(IsNumberExist(Matrix, 3, 3, UserNumber));
	return 0;
}

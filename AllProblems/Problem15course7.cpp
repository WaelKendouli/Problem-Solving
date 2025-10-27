#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;
int RandomNumber(short int From, short int To)
{
	return  rand() % ((To - From + 1) + From);
}
short int TakeNumber()
{
	short int UserInput;
	cout << "\n  Enter the Number to count ? :\n";
		cin >> UserInput;
		return UserInput;
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
short int CheckHowManyNumberRepeated(short int Matrix[3][3], short int Row, short int Col, short int UserNumber)
{
	
	short int counter = 0;
	for (short i = 0; i < Row; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			if (Matrix[i][j]==UserNumber)
			{
				counter++;
			}

		}

	}
	return counter;
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
short int UserNumber = TakeNumber();
	cout << "The Number " << UserNumber << " count in  Matrix is " << CheckHowManyNumberRepeated(Matrix, 3, 3, UserNumber);
	return 0;
}

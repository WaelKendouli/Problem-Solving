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
bool CheckIfNumberExistedInBothMatrixes(short int Matrix[3][3], short int Number, short int Row, short int Col)
{

	for (short i = 0; i < Row; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			if (Matrix[i][j] == Number)
			{
				return true;
			}

		}

	}
	return false;
}


void AddCommunElemnts(short int Matrix[3][3], short int Matrix2[3][3], short int Row, short int Col)
{
	
	short int Number;
	cout << "Intersected Numbers Are :\n";
	for (short i = 0; i < Row; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			Number = Matrix2[i][j];
			if (CheckIfNumberExistedInBothMatrixes(Matrix,Number,3,3))
			{
				cout << Number<<"\t";
			}

		}

	}
	
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
	short int Matrix2[3][3];
	FillMatrixWithRandomNumbers(Matrix);
	cout << "The following is a 3 x 3 Matrix :" << endl;
	PrintRandomMatrix(Matrix);
	FillMatrixWithRandomNumbers(Matrix2);
	cout << "The following is a 3 x 3 Matrix  2 :" << endl;
	PrintRandomMatrix(Matrix2);
	AddCommunElemnts(Matrix, Matrix2, 3, 3);
	return 0;
}

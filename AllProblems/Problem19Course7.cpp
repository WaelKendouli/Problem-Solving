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
			RandomMatrix[i][j] = RandomNumber(1, 100);

		}

	}

}
short int MaxNumberInMatrix(short int Matrix[3][3], short int Row, short int Col)
{
	
	short int Max = Matrix[0][0];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Matrix[i][j]>Max)
			{
				Max = Matrix[i][j];
			}
			
		}
		
	}
	return Max;
}
	
short int MinNumberInMatrix(short int Matrix[3][3], short int Row, short int Col)
{

	short int Min = Matrix[0][0];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Matrix[i][j] < Min)
			{
				Min = Matrix[i][j];
			}

		}

	}
	return Min;
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
	cout << "\nMaximum Number in matrix :" << MaxNumberInMatrix(Matrix, 3, 3) << endl;
	cout<< "\nMinimum Number in matrix :" << MinNumberInMatrix(Matrix, 3, 3) << endl;
	return 0;
}

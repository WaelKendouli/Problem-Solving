#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;


int RandomNumber(short int From, short int To)
{
	return  rand() % ((To - From + 1) + From);
}
int SumColumnInRandomMatrix(short int RandomMatrix[3][3], int Row, int Col)
{
	int RowSum = 0;

	for (int i = 0; i < Row; i++)
	{
		RowSum = RowSum + RandomMatrix[i][Col];
	}
	return RowSum;

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

void PrintRandomMatrix(short int RandomMatrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << setw(3) << RandomMatrix[i][j] << " ";
		}
		cout << "\n";
	}
}
void PrintColSums(short int RandomMatrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Sum of Col " << i + 1 << " = " << SumColumnInRandomMatrix(RandomMatrix, 3, i) << endl;
	}

}
int main()
{
	srand((unsigned)time(NULL));
	short int RandomMatrix[3][3];

	FillMatrixWithRandomNumbers(RandomMatrix);
	cout << "The following is a 3 x 3 Matrix :" << endl;
	PrintRandomMatrix(RandomMatrix);
	PrintColSums(RandomMatrix);

	return 0;
}


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
int SumOfMatrix(short int Matrix[3][3], short Row, short Col)
{
	int Sum = 0;
	for (short i = 0; i < Row; i++)
	{
		for (short j = 0; j < Col; j++)
		{
			Sum = Sum + Matrix[i][j];
		}

	}
	return Sum;
}
bool CheckIfMatrixEqaulEachOther(short int Matrix[3][3], short int Matrix2[3][3])
{
	return(SumOfMatrix(Matrix, 3, 3) == SumOfMatrix(Matrix2, 3, 3));
	
}
string IsMatrixEqaulEachOther(bool Result)
{
	if (Result == true)
		return "yes,Matrixes are equal";
	else
		return "No , Matrixes are not equal";
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
	cout << "The following is a 3 x 3 Matrix 2 :" << endl;
	PrintRandomMatrix(Matrix2);
	
	cout << IsMatrixEqaulEachOther(CheckIfMatrixEqaulEachOther(Matrix,Matrix2));
	return 0;
}


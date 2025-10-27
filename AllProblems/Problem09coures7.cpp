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
void PrintMiddelRow(short int Matrix[3][3], int Row,int col)
{
	short MiddelRow = Row / 2;
	for (short j = 0; j < col; j++)
	{
		printf("      %0*d", 2, Matrix[MiddelRow][j]);
	}
	cout << "\n";
}
void PrintMiddelCol(short int Matrix[3][3], int Col,int Row)
{
	short MiddelCol = Col / 2;
	for (short j = 0; j < Row; j++)
	{
		printf("      %0*d", 2, Matrix[j][MiddelCol]);

	}
	cout << "\n";
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
	cout << "Middel Row of Matrix1 is :" << endl;
	PrintMiddelRow(Matrix, 3,3);
	cout << "Middel Col of Matrix1 is :" << endl;
	PrintMiddelCol(Matrix, 3,3);
	return 0;
}

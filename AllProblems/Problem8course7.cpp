

#include <iostream>
#include <cstdlib>
#include <iomanip>
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
void ProdutMatrix(short int ProductMatrix[3][3],short int Matrix[3][3],short int Matrix2[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ProductMatrix[i][j] = Matrix[i][j] * Matrix2[i][j];
		}
		cout << "\n";
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
	short int ProductMatrix[3][3];
	FillMatrixWithRandomNumbers(Matrix);
	cout << "The following is a 3 x 3 Matrix :" << endl;
	PrintRandomMatrix(Matrix);
	cout << "The following is an other 3 x 3 Matrix :" << endl;
	FillMatrixWithRandomNumbers(Matrix2);
	PrintRandomMatrix(Matrix2);
	cout << "The following is a 3 x 3 Product Matrix :" << endl;
	ProdutMatrix(ProductMatrix, Matrix, Matrix2);
	PrintRandomMatrix(ProductMatrix);
	return 0;
}



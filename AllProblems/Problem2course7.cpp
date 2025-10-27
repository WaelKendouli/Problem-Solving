#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;


int RandomNumber(short int From, short int To)
{
	return  rand() % ((To - From + 1) + From);
}
int SumRowInRandomMatrix(short int RandomMatrix[3][3], int Row, int Col)
{
	int RowSum = 0;
	
		for (int j = 0; j < Col; j++)
		{
	RowSum = RowSum + RandomMatrix[Row][j];
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
void PrintRowSums(short int RandomMatrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Sum of Row " << i + 1 << " = " << SumRowInRandomMatrix(RandomMatrix, i, 3)<<endl;
	}

}
int main()
{
	srand((unsigned)time(NULL));
	short int RandomMatrix[3][3];
	
	FillMatrixWithRandomNumbers(RandomMatrix);
	cout << "The following is a 3 x 3 Matrix :" << endl;
	PrintRandomMatrix(RandomMatrix);
	PrintRowSums(RandomMatrix);

	return 0;
}




#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

short int FindDifrentValue(short int Matrix[3][3])
{	short int DiffrentValue;
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			if (Matrix[i][j]!=0)
			{
				DiffrentValue = Matrix[i][j];
				return DiffrentValue;
			}

		}
	}
}

bool CheckIfIdentityMatrix(short int Matrix[3][3])
{
	short int FirstDiagValue = Matrix[0][0];
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			if (i == j&& Matrix[i][j] != FirstDiagValue)
			{
				return false;
			}

			else if (i != j &&Matrix[i][j] != 0 )
			{
				return false;
			}

		}

	}
	return true;
}

string IsMatrixIdenticalToEachOther(bool Result)
{
	if (Result == true)
	{
		return "\nYes,Matrix is Scalar\n";
	}
	else
	{
		return "\nNo,Matrix is not Scalar\n";
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
	short int Matrix[3][3] = { {8,0,0},{0,8,0},{0,0,8} };
	//short int Matrix[3][3] = { {8,2,0},{3,7,1},{2,2,10} };
	cout << "The following is a 3 x 3 Matrix :" << endl;
	PrintRandomMatrix(Matrix);
	cout << IsMatrixIdenticalToEachOther(CheckIfIdentityMatrix(Matrix));
	return 0;
}
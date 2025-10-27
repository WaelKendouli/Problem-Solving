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
bool CheckIfIdentityMatrix(short int Matrix[3][3])
{

	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			if (i == j&&Matrix[i][j] == 1)
			{
				return true;
			}
			
			else if (i != j &&Matrix[i][j] != 0)
				{
				return false;
				}
			
		}

	}
	
}

string IsMatrixIdenticalToEachOther(bool Result)
{
	if (Result==true)
	{
		return "\nYes,Matrixes Are Identical\n";
	}
	else
	{
		return "\nNo,Matrixes Are not Identical\n";
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
	FillMatrixWithRandomNumbers(Matrix);
	cout << "The following is a 3 x 3 Matrix :" << endl;
	PrintRandomMatrix(Matrix);
	cout << IsMatrixIdenticalToEachOther(CheckIfIdentityMatrix(Matrix));
	return 0;
}

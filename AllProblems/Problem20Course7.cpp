#include <iostream>
using namespace std;

string PalindromMatrixOrNot(short int Matrix[3][3], short int Row, short int Col)
{

	short int Min = Matrix[0][0];
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col/2; j++)
		{
			if (Matrix[i][j] != Matrix[i][Col-j-1])
			{
				return "No , Not a Palindrom Matrix";
			}

		}

	}
	return "Yes , Its a Palindrom Matrix";
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
	
	short int Matrix[3][3]= {{1,2,1}, {5,5,5,},{7,3,7} } ;
	short int Matrix2[3][3] = { {1,2,1}, {5,5,5,},{7,3,8} };
	cout << "The following is a 3 x 3 Matrix :" << endl;
	PrintRandomMatrix(Matrix2);
	cout << PalindromMatrixOrNot(Matrix2, 3, 3);

}



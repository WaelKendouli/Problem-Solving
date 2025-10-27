#include <iostream>
#include<iomanip>
using namespace std;


void FillOrdredMatrix(int Matrix[3][3])
{
	short int counter = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Matrix[i][j] = counter;
			counter++;
		}
		cout << "\n";
	}
}
void ShowOrdredMatrix(int Matrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << Matrix[i][j] << "  ";
		}
		cout << "\n";
	}
}

void InvertMatrix(short int row, short int col, int Matrix[3][3], int Matrix2[3][3])
{
	

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
				Matrix2[j][i] = Matrix[i][j];
		}
		cout << "\n";
	}
		
	
}
int main()
{
	int Matrix[3][3];
	int Matrix2[3][3];
	cout << "The following is a 3 x 3 Matrix :" << endl;
	FillOrdredMatrix(Matrix);
	ShowOrdredMatrix(Matrix);
	cout << "The following is a 3 x 3 Invrted Matrix :" << endl;
	InvertMatrix(3, 3, Matrix,Matrix2);
	ShowOrdredMatrix(Matrix2);

	return 0;
}

#include <iostream>
using namespace std;
float ReadDimention()
{
	float D;
	cout << "Dimention : " << endl;
	cin >> D;
	return D;
}
float CalculateCircelAreaInscribedInSquare(float D)
{
	float Area;
	float const PI = 3.14159265359;
	Area = PI * pow(D / 2, 2);
	return Area;
}
void PrintCircelAreaInscribedInSquare(float Area)
{
	cout << "Area = " << Area;
}
int main()
{
	PrintCircelAreaInscribedInSquare(CalculateCircelAreaInscribedInSquare(ReadDimention()));

	return 0;
}


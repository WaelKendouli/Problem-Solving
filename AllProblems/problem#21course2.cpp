#include <iostream>
using namespace std;
float ReadDimention()
{
	float D;
	cout << "Dimention : " << endl;
	cin >> D;
	return D;
}
float CalculateCircelAreaAlongCircumfaces(float D)
{
	float Area;
	float const PI = 3.14159265359;
	Area = pow(D, 2) / (PI * 4);
	return Area;
}
void PrintCircelAreaAlongCircumfaces(float Area)
{
	cout << "Area = " << Area;
}
int main()
{
	PrintCircelAreaAlongCircumfaces(CalculateCircelAreaAlongCircumfaces(ReadDimention()));
	return 0;
}

	







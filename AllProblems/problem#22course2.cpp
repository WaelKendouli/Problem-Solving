#include <iostream>
using namespace std;
void ReadDimention(float& a , float& b)
{
	
	cout << "Dimention 1 : " << endl;
	cin >> a;
	cout << "Dimention 2 : " << endl;
	cin >> b;
	
}
float CalculateCircelAreaInscribedInIsolatedTriangle(float a , float b)
{
	float Area;
	float const PI = 3.14159265359;
	float P = (2 * a - b) / (2 * a + b);
	Area = PI * pow(b , 2)/ 4 * (P);
	return Area;
}
void PrintResult(float Area)
{
	cout << "Area = " << Area;
}
int main()
{
	float a, b;
	ReadDimention(a, b);
	PrintResult(CalculateCircelAreaInscribedInIsolatedTriangle(a, b));
	return 0;
}


#include <iostream>
using namespace std;


void ReadDimention(float& a, float& b ,float& c)
{

	cout << "Dimention 1 : " << endl;
	cin >> a;
	cout << "Dimention 2 : " << endl;
	cin >> b;
	cout << "Dimention 3 : " << endl;
	cin >> c;
}
float CalculateCircelAreaAround_IT_Triangle(float a, float b , float c)
{
	float Area ,T;
	float const PI = 3.14159265359;
	float P = (a+b+c) /2;
	T =  ((a * b * c) / (4 * sqrt(P * (P - a) * (P - b) * (P - c))));
	Area = PI * pow(T, 2);
	return Area;
}
void PrintResult(float Area)
{
	cout << "Area = " << Area;
}
int main()
{
	float a, b,c;
	ReadDimention(a, b, c);
	PrintResult(CalculateCircelAreaAround_IT_Triangle(a, b, c));
	
	return 0;
}



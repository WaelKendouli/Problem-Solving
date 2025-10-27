
#include <iostream>
using namespace std;
float circelarea_isolated_triangle(float a, float b)
{
float const pi = 3.14;
float area;
   area = pi * (pow(b, 2) / 2) * (2 * a - b / 2 * a + b) ;
   return area;

}

int main()
{
	float a, b ;
   cout << " a: \n";
   cin >> a;
   cout << " b: \n";
   cin >> b;
   cout << " area= "<<circelarea_isolated_triangle(a,b);

   return 0;
}





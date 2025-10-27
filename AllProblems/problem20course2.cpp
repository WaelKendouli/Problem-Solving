

#include <iostream>
using namespace std;

float circelarea_in_square(float A )
{
 float area;
	float const pi = 3.14;
area = pi * pow(A / 2, 2);
return area;

}
int main()
{
	 
	float A;
   cout << " A: \n";
   cin >> A;
	   cout << " area = "<<circelarea_in_square(A);
	   return 0;
}



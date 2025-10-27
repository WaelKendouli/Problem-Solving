

#include <iostream>

using namespace std;
float circelarea_circumference(float l)
{
float const pi = 3.14;
float area;
area = pow(l, 2) / 4 * pi ;

return area;
}
int main()
{
    
    float l ;
    cout << " L :\n";
    cin >> l;
    cout << " Area = " << circelarea_circumference(l);
    return 0;
}



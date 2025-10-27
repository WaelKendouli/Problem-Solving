

#include <iostream>
using namespace std;
float circel_area(float d)
{
    float area;
    double const pi = 3.14;
    area = pi * pow(d, 2);
    return area;
}

int main()
{
    
    float d, area;

    cout << " First Dimention :\n";
    cin >> d;
    cout << " area =  " << circel_area(d);
    return 0;
}




#include <iostream>

using namespace std;
float circle_arbtriang_func(float a,float b,float c)
{
float const pi = 3.14;
float p, area;
p = (a + b + c) / 2 ;
    area = pi * pow(a * b * c / ( 4 * sqrt(p * (p - a) * (p - b) * (p - c))), 2) ;
    return area;
}
int main()
{
    
    float a, b, c ;

    cout << " a :\n";
    cin >> a;
    cout << " b :\n";
    cin >> b;
    cout << " c :\n";
    cin >> c;
    
        cout << "area : " << circle_arbtriang_func( a, b, c);
        return 0;
}



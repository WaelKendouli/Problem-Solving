

#include <iostream>
using namespace std;

int main()
{
    double const pi = 3.14;
    double r , area ;

    cout << " First Dimention :\n";
    cin >> r;
    area = pi * pow(r, 2);
    cout << " area = " << ceil(area) ;
    return 0;
}


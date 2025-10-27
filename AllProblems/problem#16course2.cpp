#include <iostream>
using namespace std;



void readdimentions(float& a, float& d)
{
    cout << "  dimentoin 1 : " << endl;
    cin >> a;
    cout << "  dimentoin 2 : " << endl;
    cin >> d;
}
float AreaRectcalculater(float& a, float& d)
{
    return a*sqrt((d*d)-(a*a));
}
void showresult(float area)
{
    cout << " Area = " << area << endl;
}
int main()
{
    float a, d;
    readdimentions(a, d);
    showresult( AreaRectcalculater(a,d));

    return 0;
}





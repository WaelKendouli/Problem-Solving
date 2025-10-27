

#include <iostream>
using namespace std;

float ReadDim( )
{
    float D;
    cout << " Dimentions  : \n";
    cin >> D;
    return D;
}
float circle_area_diameter(float D)
{
    double const PI = 3.14;
    float AREA = PI * pow(D, 2);
    return AREA;


       

}
void PrintArea(float Area)
{
    cout << " area = " << Area;
}
int main()
{
    
    
    PrintArea(circle_area_diameter(ReadDim()));
    return 0;


}
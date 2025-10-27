#include <iostream>
using namespace std;
void readdimentions(int& a,int& b)
{
    cout << "  dimentoin 1 : " << endl;
        cin>>a;
        cout << "  dimentoin 2 : " << endl;
        cin >> b ;
}
float areacalculater(int& a, int& b)
{
    return(float)a * b;
}
void showresult(float area)
{
    cout << " Area = " << area << endl;
}
int main()
{
    int a, b;
    readdimentions(a, b);
    showresult(areacalculater(a, b));

    return 0;
}



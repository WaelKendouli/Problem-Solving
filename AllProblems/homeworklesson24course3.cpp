
#include <iostream>
using namespace std;

int main()
{
    int A, B;
    cout << "  First Number A :  \n";
    cin >> A;
    cout << "  Second Number B :  \n";
    cin >> B;
    cout << A << " = " << B << " is " << (A == B)<<endl;
    cout << A << " != " << B << " is " << (A != B) << endl;
    cout << A << " > " << B << " is " << (A > B) << endl;
    cout << A << " >= " << B << " is " << (A >= B) << endl;
    cout << A << " <= " << B << " is " << (A <= B) << endl;

    return 0;

}
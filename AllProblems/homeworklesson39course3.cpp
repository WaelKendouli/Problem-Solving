

#include <iostream>
using namespace std;

int main()
{
    int arr[3];
    float S, averag;
    cout << "please enter GRAEDE 1 : " << endl;
    cin >> arr[0];
    cout << "please enter GRAEDE 2 : " << endl;
    cin >> arr[1];
    cout << "please enter GRAEDE 3 : " << endl;
    cin >> arr[2];
    S = arr[0] + arr[1] + arr[2];
    averag = S / 3;
    cout << " Average : " << endl;
    cout << averag;
    return 0;
}

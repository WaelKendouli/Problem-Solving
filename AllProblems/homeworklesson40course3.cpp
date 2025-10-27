

#include <iostream>
using namespace std;
void readgrades( int arr[3])
{
    cout << "please enter GRAEDE 1 : " << endl;
    cin >> arr[0];
    cout << "please enter GRAEDE 2 : " << endl;
    cin >> arr[1];
    cout << "please enter GRAEDE 3 : " << endl;
    cin >> arr[2];

 cout << "***********************\n";

}
float calc_avreage(int arr[3])
{
    float S, Average;
    S = arr[0] + arr[1] + arr[2];
    Average = S / 3;
    return Average;
}

int main()
{
    int arr[3];
    readgrades(arr);
    cout << "Average of grades is : " << calc_avreage(arr) << endl;
	return 0;
}
   

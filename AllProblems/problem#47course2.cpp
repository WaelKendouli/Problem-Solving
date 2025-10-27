#include <iostream>
using namespace std;


int ReadPositiveNumber(string str)
{
    int Number;
    do
    {
        cout << str;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}
float CalculateMounths(float loanamount ,float mounthlypaiment)
{

    return loanamount / mounthlypaiment;
}
int main()
{
       float loanamount = ReadPositiveNumber("Loan Mount :\n");
    float mounthlypaiment = ReadPositiveNumber("Mounthly Payment:\n");
    cout << "Mounths = " << CalculateMounths(loanamount , mounthlypaiment);
}


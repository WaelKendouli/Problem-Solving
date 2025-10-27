#include <iostream>
using namespace std;



float ReadPositiveNumber(string str)
{
    float Number;
    do
    {
        cout << str;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}
float CalculateMounths(float loanamount, float mounth)
{

    return loanamount / mounth;
}
int main()
{
    float loanamount = ReadPositiveNumber("Loan Mount :\n");
    float mounth = ReadPositiveNumber("Mounths :\n");
    cout << "mounthlypaiment = " << CalculateMounths(loanamount, mounth);
}


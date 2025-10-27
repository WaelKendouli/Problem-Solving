#include <iostream>
using namespace std;
struct stPiggyBank
{
    int penny, nickle, dime, quarter, dollar;
};
stPiggyBank ReadPiggyBankContent()
{
    stPiggyBank content;
    cout<<"Penneis :"<<endl;
    cin >> content.penny;
    cout<<"Nickles :"<<endl;
    cin >> content.nickle;
    cout<<"Quarters :"<<endl;
    cin >> content.quarter;
    cout<<"Dimes :"<<endl;
    cin >> content.dime;
    cout<<"Dollars :"<<endl;
    cin >> content.dollar;
    return content;
}
int CalculateInPenny(stPiggyBank content)
{
    int totalpennies = 0;
   totalpennies = content.penny  + content.nickle * 5 + content.dime * 10 + content.quarter * 25 + content.dollar * 100;
   return totalpennies;
}

int main()
{
    stPiggyBank totalpennies = ReadPiggyBankContent();
    cout << "Money In Pennies = " << CalculateInPenny(totalpennies)<<endl;
    cout << "Money In Dollars = " << (float) CalculateInPenny(totalpennies)/100<<endl;

    return 0;
}



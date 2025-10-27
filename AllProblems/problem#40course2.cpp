// problem#40course2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include <iostream>
using namespace std;
float ReadPositiveNumber(string str)
{
    float Number;
    cout << str;
    cin >> Number;
    return Number;
}
float CalculateTotalAndBillTax(float totalbill)
{
    
    totalbill = totalbill * 1.1;
    totalbill =  totalbill  * 1.16;
    return totalbill;
}
int main()
{
    float billvalue, totalbill;
    totalbill= ReadPositiveNumber(" Total Value : \n");
    
    cout << "**********************\n";
    cout << CalculateTotalAndBillTax(totalbill);


    return 0;

}




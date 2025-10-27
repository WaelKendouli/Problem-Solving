#include <iostream>
using namespace std;


int ReadPINCode(string str)
{
   int Number;
        cout << str;
        cin >> Number;
    return Number;
}
bool testonly()
{
    int  PINCODE=0;
    do
    {
       PINCODE== ReadPINCode("PIN code :\n");
       if (PINCODE == 1234)
       {
           return 1;
       }
       else
       {
           cout << "Wrong PIN\n";
           system("color 4F");
          
       }
    } while (PINCODE!=1234);
    return 0;
}

int main()
{

    if (testonly())
    {
        system("color 2F");
        cout << "Your Balance : " << 7500 << endl;
    };
   
   
}



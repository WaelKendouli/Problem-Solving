#include <iostream>
#include <string>
using namespace  std;



int main()
{
    string fullname , str1 , str2 , str3 , str4  ;
    cout << " please enter your name :  " << endl;
    getline(cin, fullname);
    cout << " please enter your 2 nd string :  " << endl;
    getline(cin, str1);
    cout << " please enter your 3 rd string :  " << endl;
    getline(cin, str2);
    str3 = str1 + str3;
    cout << " **********************************************  " << endl;
    cout << "  the length of your sring 1  :  " << fullname.length()<< endl;
    cout << "characters at 0 , 2 , 4 , 7 :  " << fullname[0] <<"  " << fullname[2] <<"  " << fullname[4] <<"  " << fullname[7] << endl;
    cout << " concatonation of string 1 and string 2 :  " << str3 << endl;
    str4 = stoi(str1) *  stoi(str2);
    cout << str1 << " * " << str2 << " = " << str4<< endl;

    return 0;
}


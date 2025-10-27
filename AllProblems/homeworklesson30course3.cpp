

#include <iostream>
#include<string>

using namespace std;

int main()
{

   /* string st1 = "43.22";
    int n_int = stoi(st1);
    float n_float = stof(st1);
    double n_double = stod(st1);

    cout<< n_int << endl;
    cout<< n_float  << endl;
    cout<< n_double  <<endl;*/
    int N1 = 20 , num_int ;
    double N2 = 33.5;
    float N3 = 55.23;
    string str , str2 , str3 ;
   /* str = to_string(N1);
    cout << str << endl;
    str2 = to_string(N2);
    cout << str2 << endl;*/
    str3 = to_string(N3);
    cout << str3 << endl;
    num_int = (int)N3;
    cout << num_int << endl;

    return 0;
}


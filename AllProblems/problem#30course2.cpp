#include <iostream>
#include<string>
using namespace std;
int ReadPositiveNumber(string Message)
{
    int N;
    do
    {
cout << Message << endl;
    cin >> N;
    } while (N<0);
    
    return N;
}
int Calfactorial(int N)
{
    int Factorial = 1;
    for (int i = 1; i <= N; i++)
    {
        Factorial = Factorial * i;
    }
    return Factorial;
}

int main()
{
    
    cout << Calfactorial(ReadPositiveNumber("Number ? :"));

}


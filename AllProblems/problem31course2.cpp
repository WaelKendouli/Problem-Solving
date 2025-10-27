#include <iostream>
using namespace std;


int readNum()
{
	int n;
   cout << "Number : \n";
  cin >> n;
   return n;
}
void PowerOf2_3_4(int n)
{
	int PowOf2 = n * n;
	int PowOf3 = n * n * n;
	int PowOf4 = n * n * n * n;
	cout << PowOf2 << endl;
	cout << PowOf3 << endl;
	cout << PowOf4 << endl;
}
int main()
{
	
	PowerOf2_3_4(readNum());
 
   return 0;
}



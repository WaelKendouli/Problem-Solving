#include <iostream>
#include<string>
using namespace std;


int ReadNum(string Mes1)
{
	int N;
	cout << Mes1 << endl;
	cin >> N;
	return N;
}
int ReadPower(string Mes2)
{
	int M;
	cout << Mes2 << endl;
	cin >> M;
	return M;
}
int PowerOfM(int N ,int M)
{
	 int result =1;
	 if (M == 0)
		 return result;
	for (int i = 1; i <=M; i++)
	{
		result = result * N;
	}
	return result;
}
int main()
{
	cout << endl << "Result =  " << PowerOfM(ReadNum("Number :"), ReadPower("Power :"));
   return 0;
}


#include <iostream>
#include <string>
#include <vector>
using namespace std;
string JoinString(vector <string>& vString , string delimeter)
{
	string S = "";
	for (string& VectorElement : vString)
	{
		S = S + VectorElement + delimeter;
	}
	return S.substr(0, S.length() - delimeter.length());
}
int main()
{
	vector <string> vString = { "Wael","Mohammed","Rami","Sabrina","Yacin" };
	cout << "\nVector After Join : \n";
	
	cout<<JoinString(vString, " , ");
}



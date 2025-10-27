#include <iostream>
#include <string>
#include <vector>
using namespace std;
string JoinString(vector<string>& vString, string delimeter)
{
	string S="";
	for (string& VectorElem : vString)
	{
		S = S + VectorElem + delimeter;
	}
	return S.substr(0,S.length()-delimeter.length());
}
string JoinString(string ArrString[],short length , string delimeter)
{
	string S = "";
	for (short i = 0; i < length; i++)
	{
		S = S + ArrString[i] + delimeter;
	}
		
	
	return S.substr(0,S.length()- delimeter.length() );
}
int main()
{
	
vector	<string> vString  = { "Wael","Mohammed","Rami","Sabrina","Yacin" };
string ArrString[]= { "Wael","Mohammed","Rami","Sabrina","Yacin" };
	cout << "\nVector After Join : \n";

	cout << JoinString(vString, " , ");
	cout << "\nArray After Join : \n";
	cout << JoinString(ArrString,5 ," , ");

}

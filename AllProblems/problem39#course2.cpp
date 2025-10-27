
#include <iostream>
using namespace std;
struct stBillpaid
{
	float totalbill, cashpaid;
};
float ReadBill(string str1 )
{

	float Number;
	cout << str1;
	cin >> Number;
	return Number;
}
float Result(float totalbill,float cashpaid)
{
	return(totalbill - cashpaid);
	
}
int main()
{
	
	cout << " result : " << Result(ReadBill("Total bill\n"), ReadBill("Cash paid\n"));
   

}


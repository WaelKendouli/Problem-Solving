#include <iostream>
using namespace std;
int salesreader()
{
	float totalsale;
cout << " Total sales : " << endl;
	cin >> totalsale;
	return totalsale;
}
float CommisionPersentage(float totalsale)
{
	if (totalsale >= 1000000)
		return  0.01;
	else if (totalsale >= 500000)
		return  0.02;
	else if (totalsale >= 100000)
		return  0.03;
	else if (totalsale >= 50000)
		return  0;
}
float persentage(float totalsale)
{
	return totalsale * CommisionPersentage(totalsale);
}


int main()

{
	float totalsales = salesreader();
	cout << " Persentage = "  << CommisionPersentage(totalsales)<< endl;

	cout << "Your Persentage = "  << persentage(totalsales)<< endl;
	return 0;
}



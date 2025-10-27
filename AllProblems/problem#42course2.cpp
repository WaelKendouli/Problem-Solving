#include <iostream>
using namespace std;
struct stTimeComponents
{
	int Seconds, Minutes, Hours, Days;
};
int ReadPositiveNumber(string str)
{
	int Number;
	do
	{
		cout << str;
		cin >> Number;
	} while (Number<=0);
	
	return Number;
}
stTimeComponents ReadTime()
{
	stTimeComponents time;
	time.Days = ReadPositiveNumber("Days :");
	time.Hours = ReadPositiveNumber("Hours :");
	time.Minutes = ReadPositiveNumber("Minutes :");
	time.Seconds = ReadPositiveNumber("Seconds :");

	return time;
}
double TimeInSeconds(stTimeComponents time)
{
	return (double)((time.Days * 24 * 3600) + (time.Hours * 3600) + (time.Minutes * 60) + time.Seconds);

}

int main()
{
	cout<<TimeInSeconds(ReadTime())<<" Seconds\n";
	return 0;
}



#include <iostream>
using namespace std;
struct stTimeComponents
{
	int Seconds, Minutes, Hours, Days , RemainSecs, RemainMins , RemainHours , RemainDays ;
};
int ReadPositiveNumber(string str)
{
	int Number;
	do
	{
		cout << str;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}
stTimeComponents ReadTime()
{
	stTimeComponents time;
	time.Seconds = ReadPositiveNumber("Seconds :\n");

	return time;
}
stTimeComponents TimeConverter(stTimeComponents time)
{
	time.Minutes = time.Seconds / 60;
	time.RemainSecs = time.Seconds % 60;
	time.Hours = time.Minutes / 60;
	time.RemainMins = time.Minutes % 60;
	time.Days = time.Hours / 24;
	time.RemainHours = time.Hours % 24;
	return time;
}
void PrintTimeInSecs(stTimeComponents time )
{
	cout << time.Days << ":" << time.RemainHours << ":" << time.RemainMins << ":" << time.RemainSecs;
}
int main()
{
	PrintTimeInSecs(TimeConverter(ReadTime()));
}


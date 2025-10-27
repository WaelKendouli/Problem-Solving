#include <iostream>
using namespace std;
int readGrade(int from , int to)
{
	int n;
	do
	{
cout << "Grade between 0 and 100 :" << endl;
	cin>> n;
	} while (n <from || n> to);
	
	return n;
}
char GradeRank(int n)
{
	if (n >= 90)
		return 'A';
	else if (n >= 80)
		return 'B';
	else if (n >= 70)
		return 'C';
	else if (n >= 60)
		return 'D';
	else if (n >= 50)
		return 'E';
	else 
		return 'F';

}


int main()
{
	cout << GradeRank(readGrade(0, 100));
	return 0;
}



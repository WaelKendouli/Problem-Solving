#include <iostream>
using namespace std;

enum enStatus {pass=1 ,fail=2};
int readMark()
{
	int mark;
	cout << "enter your mark : " << endl;
	cin >> mark;
	return mark;
}
enStatus checkIfPassed(int mark)
{
	
	if (mark >= 50)
		return enStatus::pass;
	else
		return enStatus::fail;
	 
}
void printresults(int mark)
{
	
	if (checkIfPassed(mark) == enStatus::pass)
		cout << "passed" << endl;
	else
		cout << "failed" << endl;
}

int main()
{
	printresults( readMark());
	return 0; 
}


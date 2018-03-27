#include<iostream>
using namespace std;

void main()
{
	int exam, programsDone;
	cout<<"What was your exam grade:\t";
	cin>>exam;
	cout<<"How many programs have you completed:\t";
	cin>>programsDone;
	if (exam>=60 && programsDone>=10)
		cout<<"\n\nPassed\n\n";
	else
		cout<<"\n\nFailed\n\n";
}
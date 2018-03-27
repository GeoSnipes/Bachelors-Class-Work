#include<iostream>
using namespace std;

int number, x;
int grades(int gnumber);
int compare(int glist[], int number);


void main()
{
	cout<<"How many grades will you enter:\t";
	cin>>number;
	grades(number);
	
}

int grades(int gnumber)
{
	
	int grade[10];
	for (x=0;x<gnumber;x++)
	{
		cout<<"Enter the grade:\t";
		cin>>grade[x];
	}
	compare(grade, number);
	return 1;
}

int compare(int glist[], int number)
{
	int goodgrade[10];
	for (x=0;x<number;x++)
	{
		if (glist[x]>=90)
		{
			goodgrade[x]=glist[x];
		}
	}
	cout<<goodgrade<<endl;
	return 1;
}
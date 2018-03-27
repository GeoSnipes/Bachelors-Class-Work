#include <iostream>
using namespace std;
/*
*/
void readRange(long [], int);
void displayRange (long,long, int);
void main()
{ 
	long income[50];
	int count=0; 
	cout<<"Input yearly income for a number of employees (end with negative): "<<endl;
	readRange(income, count);
	cout<<endl;
	cout<<endl;
}

void readRange(long income[], int count)
{
	int x=0, ans;
	long smallest=INT_MAX, largest=0;

	cout<<"Income: \t";
	cin>>ans;
	while (ans>0)
	{
		income[x]=ans;
		if (ans<smallest)
			smallest=ans;
		if(ans>largest)
			largest=ans;
		x++;
		count++;
		cout<<"Income: \t";
		cin>>ans;
	}
	displayRange(smallest, largest, count);
	
}

void displayRange(long smallest, long largest, int count)
{
	
	cout<<"Number of employees for which the income has been input:  : \t"<<count<<endl;
	cout<<"The range of incomes: ["<<smallest<<","<<largest<<"]"<<endl;
}


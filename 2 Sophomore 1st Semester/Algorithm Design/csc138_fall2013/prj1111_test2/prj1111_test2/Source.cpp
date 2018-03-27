#include<iostream>
using namespace std;
/*
Input- array of integer numbers
Output- new array in which each element is replaced by the difference between the maximum element of the given array and itself.
*/

int max(int, int []);
void makenewarray(int, int, int [], int []);
void displayarrays(int , int [], int []);

void main()
{
	//variables
	int n, x, maxv;
	int oldarray[30], newarray[30];

	//algorithem
	cout<<"How many values do you want to enter:\t";
	cin>>n;
	cout<<"\nEnter the "<<n<<" values:\n";
	for(x=0;x<n;x++)
	{
		cin>>oldarray[x];
	}
	maxv=max(n, oldarray);
	makenewarray(n, maxv, oldarray, newarray);
	displayarrays(n, oldarray, newarray);
}

int max(int n, int oldarray[50])
{
	int x, max=-999999;
	for(x=0;x<n;x++)
	{
		if (oldarray[x]>max)
			max=oldarray[x];
	}
	return max;
}

void makenewarray(int n, int maxv, int oldarray[50], int newarray[50])
{
	int x;
	for(x=0;x<n;x++)
	{
		newarray[x]=maxv-oldarray[x];
	}
}

void displayarrays(int n, int *oldarray, int *newarray)
{
	int x;
	cout<<"\n\nThe old array of "<<n<<" elements is:\n";
	for(x=0;x<n;x++)
	{
		cout<<oldarray[x]<<"\t";
	}
	cout<<"\n\nThe new array of "<<n<<" elements is:\n";
	for(x=0;x<n;x++)
	{
		cout<<newarray[x]<<"\t";
	}
	cout<<endl<<endl;
}

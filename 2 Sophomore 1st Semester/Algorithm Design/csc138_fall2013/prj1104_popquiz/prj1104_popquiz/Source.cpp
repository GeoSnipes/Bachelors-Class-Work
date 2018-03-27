#include <iostream>
using namespace std;

int *newarray(int, int []);
int displayarray(int , int [50], int [50]);
void main()
{
	int n, x, *b, oldarray[50];
	cout<<"How many values do you want to enter:\t";
	cin>>n;
	cout<<"Enter "<<n<<" values:\n";
	for(x=0;x<n;x++)
		cin>>oldarray[x];
	b=newarray(n, oldarray);
	displayarray(n, oldarray, b);
}

int *newarray(int n, int oldarray[50])
{
	int x, b[50];
	b[0]=oldarray[0];
	b[n-1]=oldarray[n-1];
	for (x=1;x<n-1;x++)
		b[x]=oldarray[x-1]+oldarray[x+1];
	cout<<endl<<endl;
	return b;
}
int displayarray(int n, int oldarray[50], int *b)
{
	int x;
	cout<<"Old array was:\n";
	for(x=0;x<n;x++)
		cout<<oldarray[x]<<" ";
	cout<<endl<<endl;
	cout<<"New array is:\n";
	for(x=0;x<n;x++)
		cout<<b[x]<<" ";
	cout<<endl<<endl;
	return 1;
}
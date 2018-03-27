#include<iostream>
using namespace std;

/*
Input: time
Output: the distance an object fell
*/

void main()
{	
	//Variables
	double t, distance;
	int acc=32;
	
	//Algorithm
	cout<<"How long has the object been falling: \t";
	cin>>t;
	distance=.5*acc*pow(t,2);
	cout<<"\nThe object fell for "<<distance<<" feet";
	cout<<endl<<endl;
}
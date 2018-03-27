#include<iostream>
using namespace std;

void main()
{
	int temperature, pressure;
	cout<<"What is the current temperature:\t";
	cin>>temperature;
	cout<<"What is the curent pressure:\t";
	cin>>pressure;
	if (temperature>=100 || pressure>=200)
		cout<<"\n\Warning!\n\n";
	else
		cout<<"\n\nOk\n\n";
}
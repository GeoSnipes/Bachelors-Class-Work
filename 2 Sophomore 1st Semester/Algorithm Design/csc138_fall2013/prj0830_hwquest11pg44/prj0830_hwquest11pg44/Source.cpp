#include<iostream>
using namespace std;

/*
Input: seconds
Output: the seconds converted to hours, minutes, and seconds
*/

void main()
{
	//Variables
	int secs, hours, mins, rsecs;
	
	//ALgorithm
	cout<<"How much seconds have passed: \t";
	cin>>secs;
	hours=secs/3600;
	mins=(secs%3600)/60;
	rsecs=(secs%3600)%60;
	cout<<"\n"<<secs<<" seconds can be converted to, "<<hours<<" hours "<<mins<<" minutes \nand "<<rsecs<<" seconds."<<endl<<endl;
}
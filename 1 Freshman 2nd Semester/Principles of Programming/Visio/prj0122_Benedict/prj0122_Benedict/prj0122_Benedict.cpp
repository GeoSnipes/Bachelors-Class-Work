#include <iostream>

/*
Input:year of enrollment
Output:Years spent at Benedict College
*/

using namespace std;
void main()
{
	//variables and constants
	int yearE, yearS;
	int yearC=2013;

	//instructions
	cout<<"Input your year of enrollment in Benedict:\n";
	cin>>yearE;
	yearS=yearC-yearE;
	cout<<"\nYou have spent at Benedict \n"<<yearS<<" year(s).\n";
}
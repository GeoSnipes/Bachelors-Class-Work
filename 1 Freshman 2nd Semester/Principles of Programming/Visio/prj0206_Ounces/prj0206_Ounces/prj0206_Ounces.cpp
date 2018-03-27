#include <iostream>
using namespace std;
/*
Input-Weight in ounces
Output-Weight in metric tonnes and the number of boxes of cerel ned to make 1 metric tone
*/
void main()
{
	float lmeter, cmeter, convert=1000, box;    //user entered weight, converted weight, convertion rate, and number of boxes needed
	cout<<"Enter the length in meters:\t";
	cin>>lmeter;
	cmeter=lmeter/convert;
	cout<<"\nThe length in meters converted to km is:\n"<<cmeter<<" kilometrs.\n";
	box=1/cmeter;
	cout<<"\nYou will need "<<box<<" .\n\n";
}
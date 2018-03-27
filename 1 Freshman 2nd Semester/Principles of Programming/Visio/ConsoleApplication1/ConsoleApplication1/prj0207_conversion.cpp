//Geovanni West
//Question 1 pg 42

#include <iostream>
using namespace std;
/*
Input: user entered weight
Output: converted weight and numpber of boxes needed to make one metric tonne
*/
void main()
{
	//Variables 
	float wOz,wT, nrP;					//weight in ounces, weight in tonnes, number of packages 

	//Constants
	const float mtonne=35273.92;		//convertion rate
		
	//Instructions
	cout<<"Enter the weight in ounces:\t";
	cin>>wOz;
	wT=wOz/mtonne;
	cout<<"\nThe weight in metric tonnes is "<<wT<<" metric tonnes.";
	nrP=1/wT;  
	cout<<"\n\nThe number of boxes need to make 1 metric tonne is "<<nrP<<" boxes.\n\n";
}

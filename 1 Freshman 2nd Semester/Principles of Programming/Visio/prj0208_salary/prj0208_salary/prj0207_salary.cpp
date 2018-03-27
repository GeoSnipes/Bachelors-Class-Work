//Geovanni West
//February 8, 2012
//prj0208_salary
//CSC 135 S8

#include <iostream>
using namespace std;
void main()
{
	const float iper=7.6/100;						//Increase percentage
	float uasal, imsal, umsal, iasal, retropayi;	
	cout<<"What is your annual pay:\t";
	cin>>uasal;										//annual salary before increase
	umsal=uasal/12;									//monthly salary before increase
	imsal=((iper*uasal)+uasal)/12;					//monthly salary after increase
	iasal=imsal*12;									//annual salary after increase
	retropayi=(imsal-umsal)*6;						//retroactive pay due for past 6 months
	cout<<"\n\nYour retroactive amount is:\t$"<<retropayi;
	cout<<"\n\nYour new monthly salary is $"<<imsal;
	cout<<"\n\nYour new yearly salry is $"<<iasal<<endl;
}

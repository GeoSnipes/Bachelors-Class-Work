#include <iostream>
#include <conio.h>
using namespace std;
/*
Input- Some integer numbers
Output- The smallest non negative number introduced
*/
int main()
{
	int nr = 0, min=9999999, place=0, placecheck=0;
	cout<<"Input non-negative integer numbers (end with negative number):\n";
	cin>>nr;
	while (nr >= 0 )
	{
		placecheck++;
		if (nr < min)
		{
			min = nr;
			place=placecheck;
		}
		cin>>nr;
	}
	cout<<"\n\nThe smallest number introduced was: "<<min<<endl;
	cout<<"This number was in place: "<<place<<" of the sequence.\n\n\n";
	_getch();
	return 0;
}

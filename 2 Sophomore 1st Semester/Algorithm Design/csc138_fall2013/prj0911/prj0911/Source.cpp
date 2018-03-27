#include <iostream>
using namespace std;
/*
Input: a number
Output: message denoting if the number entered is a negative, positive less than or equal to 10, or a positive number greater than 10
*/

int main()
{
	int a;
	cout<<"Enter a number: \t";
	cin>>a;
	if ((a<=10)&&(a>=0))
	{
		cout<<"This is a positive, less than 10 number."<<'\n';
	}
	else
	{
		if (a<0)
		{
			cout<<"This is a negative number."<<'\n';
		}
	    else
        {
            cout<<"This is a positive number greater than 10.\n";
        }
     }
     return 0;
}
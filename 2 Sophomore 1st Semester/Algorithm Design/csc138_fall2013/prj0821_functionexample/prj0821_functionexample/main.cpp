#include <iostream>
using namespace std;
/*
This program will accept 2 numbers and by using the funtion return method will display the sum of the 2 numbers.
Input: 2 numbers
Output:Sum
*/

int function1 (int, int);
void main()
{
    int step, a, b;
    for (step=0; step < 2; step++)
    {
		cout<<"Enter 2 numbers: ";
        cin>>a;
        cin>>b;
        cout<<"The result is: "<<function1(a,b)<<endl<<endl;
     }
}

int function1(int n, int m)
{
     return n+m;
}   


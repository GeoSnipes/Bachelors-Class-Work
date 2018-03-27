#include <iostream>
using namespace std;

char integer(double);

int main()
{
	double number;
	cout<<"Enter a number:\t";
	cin>>number;
	cout<< integer(number)<<endl;
	return 0;
}

char integer(double number)
{
	if (number>=0)
		return 'P';
	else
		return 'N';
}
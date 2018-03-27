// ErrorProgram – This program averages a series
//		 of numbers, except that it contains
//		 a fatal bug.
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	cout << "This program was designed to crash but has been fixed."
		 << endl;

	int nSum=0;
	int nNums;

	// accumulate input numbers until the
	// user enters a negative number, then
	// return the average
	nNums = 0;
	while(true)
	{
		// enter another number to add
		int nValue;
		cout << "Enter another number, to stop input enter a negative:";
		cin >> nValue;
		cout << endl;

		// if the input number is negative...
		if(nValue < 0)
		{
			// ... then output the average
			cout << "Average is: "
				 << nSum/nNums
				 << endl;
					break;
		}

		// not negative, add the value to
		// the accumulator
		nSum += nValue;
		nNums++;
	}
	cin.get();
	return 0;
}

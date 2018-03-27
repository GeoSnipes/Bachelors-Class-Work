#include<iostream>
//#include<stdlib.h>
using namespace std;
/*
Input: he yearly income for a number of people; input ends with 0 or neg.#
Output: It displays how many people's income was input and the range of the salary (the smallest and largest amounts).
 Note: the program should store the info about this array of incomes in a structure.
struct arraySpecs {
   int size, smallest, largest;
};
*/
struct arraySpecs 
{
	int size;
	double smallest, largest;
};

void rangefinder(arraySpecs &);
void display(arraySpecs);

void main()
{
	arraySpecs income;
	cout<<"Enter the income of all the people in your company. Enter a negative number to stop input.\n";
	rangefinder(income);
	display(income);
}

void rangefinder(arraySpecs &income)
{
	double salary;
	income.smallest=999999999999;
	income.largest=-1;
	income.size=0;
	cout<<"Income:   ";
	cin>>salary;
	while(salary>=0)
	{
		income.size=income.size+1;
		if (salary>income.largest)
			income.largest=salary;
		if (salary<income.smallest)
			income.smallest=salary;
		cout<<"Income:   ";
		cin>>salary;
	} 
}

void display(arraySpecs income)
{
	cout<<income.size<<" people entered their income. The salaries ranged from "<<income.smallest<<" to "<<income.largest<<".\n\n";
}

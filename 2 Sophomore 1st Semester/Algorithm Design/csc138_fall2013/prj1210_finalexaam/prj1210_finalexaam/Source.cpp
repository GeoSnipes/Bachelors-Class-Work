/*
Create the Visual C++ project  that has the following functionality: it inputs the yearly income for a number of people. The input ends when 0 or a negative number is introduced. As a result it displays how many people's income was input and the range of the salaries (the smallest and largest amounts).
 The program should store the input information in an array. For displaying the range of incomes you are required to use a function with the following prototype:  void displayRange(long, long);
*/
#include <iostream>
using namespace std;

/*
Input- income for a number of individuals
Output- Range of the income
*/

int createarray(long []);
void displayarray(long [], int);

void main()
{
	long income[50];
	int size;
	size=createarray(income);
	displayarray(income, size);
}

int createarray(long income[50])
{
	long num;
	int size=0;
	cout<<"Input yearly income for a number of employees (end with negative):\n\n";
	cout<<"Income:  ";
	cin>>num;
	while(num>0)
	{
		income[size]=num;
		size++;
		cout<<"Income:  ";
		cin>>num;
	}
	return size;//instead of making the user predefine the number of salary to be entered, the program counts the amount entered itself
}

void displayarray(long income[50], int size)
{
	int x;
	long max=-1;
	long min=999999999;
	cout<<"\nNumber of employees for which the income has been input:  "<<size<<endl<<endl;
	for (x=0; x<size; x++)
	{
		if(income[x]>max)
			max=income[x];
		if (income[x]<min)
			min=income[x];
	}
	cout<<"The range of incomes: ["<<min<<", "<<max<<"]"<<endl<<endl;
}



#include <iostream>

using namespace std;
/*
Input: Person's gender and age
Output: The person's either male or female normal maximum heart rate.
*/

double calchrate(char, int);

void main()
{
	int age;
	char gender;
	cout<<"To stop the program, enter 0 for age.\n";
	do
	{
		cout<<"\n\nWhat is your gender, enter m for male or f for female: ";
		cin>>gender;
		cout<<"What is your age: ";
		cin>>age;
		if (age!=0)
			cout<<"\nYour normal maximum heart rate is "<<calchrate(gender, age)<<endl;
	} while (age!=0);
}

double calchrate(char gend, int age)
{
	double hrate;
	if (gend=='m')
	{
		hrate=220-age;
	}
	else
	{
		hrate=(206-age)*.88;
	}
	return hrate;
}
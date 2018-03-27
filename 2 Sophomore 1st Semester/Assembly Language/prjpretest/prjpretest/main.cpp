#include<iostream>
#include<cctype>
using namespace std;

/*
Input- calories per serving, fat per serving
Output- percentage of calories from fat and the equivalent message about aha recommendation
*/

double computecaloriesfat(double,double);

void main()
{
	double calories, fat;	//Calories per serving, fat per serving 
	double percentage;	//Result of computealoriesfat is saved here
	char choice;		//At the end the program ask you you want to add another entry

	do
	{
		cout<<"Input calories per serving:\t";
		cin>>calories;
		cout<<"\nInput grams of fat per serving:\t";
		cin>>fat;
		percentage=computecaloriesfat(fat, calories);
		cout<<"\nThe percentage of calories from fat is ";
		if (percentage<30)
		{
			cout<<percentage<<"% \n\tand it meets the AHA recommendation.";
		}
		else
		{
			cout<<percentage<<"% \n\tand it exceeds the AHA recommendation.";
		}
		cout<<"\n\nContionue (Y/N):\t";
		cin>>choice;
		choice=toupper(choice);
	} while (choice=='Y');
}

double computecaloriesfat(double gramsfat, double calperserve)
{
	double caloriesfromfat;	//result of computation is saved here

	caloriesfromfat=(gramsfat*9/calperserve)*100;
	return caloriesfromfat;
}

			
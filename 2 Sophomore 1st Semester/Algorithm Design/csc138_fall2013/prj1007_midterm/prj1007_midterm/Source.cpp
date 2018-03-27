#include<iostream>
using namespace std;
/*
Input:the students grade
Output: comment on students grade
*/

void main()
{
	//variables
	char lgrade; //user's input is saved here
	
	//algorithm
	cout<<"Enter your letter grade, either A, B, C, D, or F.\nEnter Q to stop the program:\t";
	cin>>lgrade;
	while (toupper(lgrade)!='Q')
	{
		switch(lgrade)
		{
			case 'a':
			case 'A':
				cout<<"Excellent job!!!\n";
				break;
			case 'b':
			case 'B':
				cout<<"Good job!\n";
				break;
			case 'c':
			case 'C':
				cout<<"It's OK\n";
				break;
			case 'd':
			case 'D':
				cout<<"You can do better\n";
				break;
			case 'f':
			case 'F':
				cout<<"Please, try again\n";
				break;
			default:
				cout<<"\nYou did not enter a grade of either A, B, C, D, or F.\n";
				break;
		}
		cout<<"\nEnter another grade:\t";
		cin>>lgrade;
	}
	cout<<"Bye! Come Again.\n\n";
}
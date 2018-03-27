#include<iostream>
using namespace std;
/*
Input: a character
Output: whether the character is capital, common, or a number
*/

void main()
{
	//Variables
	char input, check; //User input, variable to save user response if he or she wants to continue
	
	//Algorithm
	do
	{
		cout<<"Enter an input, either a character or a number.\n";
		cin>>input;
		if (('A'<=input)&&(input<='Z'))
			cout<<"You entered the capital letter "<<input<<endl<<endl;
		else if (('a'<=input)&&(input<='z'))
			cout<<"You entered the common letter "<<input<<endl<<endl;
		else if (('0'<=input)&&(input<='9'))
			cout<<"You entered the number "<<input<<endl<<endl;
		else
			cout<<"You entered the symbol "<<input<<endl<<endl;
		cout<<"Do you want to input again (y/n):\t";
		cin>>check;
	} while ((check=='y')||(check=='Y'));
	cout<<"\n\nSee you next time.\n\n\n";
}
#include<iostream>
using namespace std;
/*
Input-User selects either if he wants to change a deciml to binary or vice versa then enters the number
Output- Program outputs the value
*/

void dectobin();
void bintodec();

void dectobin()
{
	cout<<"Enter the decimal you want to change to binary:\t";
	cin>>numdec;
	numbin=numdec

}

void bintodec()
{
	cout<<"bintodec work ";
} 

void main()
{
	int response, choicetrack;
	char choice;
	do
	{
		cout<<"Do you want to:\n"
			<<"\t1. Change a decimal to binary\n"
			<<"\t2. Change a binary to decimal\n"
			<<"\nResponse:\t";
		cin>>response;
		switch (response)
		{
			case 1:
				dectobin();
				break;
			case 2:
				bintodec();
				break;
			default:
				cout<<"Wrong entry.";
				break;
		}
		cout<<"Do you want to go again (y/n): \t";
		cin>>choice;
		switch (choice)
		{
			case 'y':
			case 'Y':
				choicetrack=1;
				break;
			case 'n':
			case 'N':
				choicetrack=0;
				break;
			default:
				cout<<"You entered a incorrect choice, program will now close";
				choicetrack=0;
				break;
		}
	} while (choicetrack==1);
}


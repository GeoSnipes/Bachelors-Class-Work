#include<iostream>
#include<string>
using namespace std;

struct personinfo
{
	string fname, lname, monthwob;
	int monthnob, dayob, yearob;
};

void readdetails(personinfo [], int);
void displaydetails(personinfo [], int);

void main()
{
	personinfo ind1[50];
	int size;
	cout<<"Enter the number of individual details you want to enter:\t";
	cin>>size;
	cout<<"Enter your details.";
	readdetails(ind1, size);
	cout<<endl<<endl;
	displaydetails(ind1, size);
}

void readdetails(personinfo individual[], int size)
{
	int i;
	cout<<endl<<"Enter the individuals' details.";
	for (i=0;i<size;i++)
	{
		cout<<endl<<"Enter the first name:\t";
		cin>>individual[i].fname;
		cout<<"Enter the last name:\t";
		cin>>individual[i].lname;
		cout<<"Enter the month of birth in number:\t";
		cin>>individual[i].monthnob;
		cout<<"Enter the day of birth:\t";
		cin>>individual[i].dayob;
		cout<<"Enter the year of birth:\t";
		cin>>individual[i].yearob;
	}
}

void displaydetails(personinfo individual[], int size)
{
	int i;
	for (i=0;i<size;i++)
	{
		switch(individual[i].monthnob)
		{
			case 1:
				individual[i].monthwob="January";
				break;
			case 2:
				individual[i].monthwob="February";
				break;
			case 3:
				individual[i].monthwob="March";
				break;
			case 4:
				individual[i].monthwob="April";
				break;
			case 5:
				individual[i].monthwob="May";
				break;
			case 6:
				individual[i].monthwob="June";
				break;
			case 7:
				individual[i].monthwob="July";
				break;
			case 8:
				individual[i].monthwob="August";
				break;
			case 9:
				individual[i].monthwob="September";
				break;
			case 10:
				individual[i].monthwob="October";
				break;
			case 11:
				individual[i].monthwob="November";
				break;
			case 12:
				individual[i].monthwob="December";
				break;
			default:
				cout<<"You did not write a number between among 1 to 12 for the month";
				break;
		}
		cout<<individual[i].fname<<" "<<individual[i].lname<<" was born on "<<individual[i].monthwob<<" "<<individual[i].dayob<<", "<<individual[i].yearob<<endl;
	}
}
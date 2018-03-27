#include <iostream>
using namespace std;

void message(char[], char[]);


void main ()
{
	char fname[20], lname[20];
	char questionf[] = "Please, enter your first name: ";
	char questionl[] = "Please, enter your last name: ";
	cout<<questionf;
	cin>>fname;
	cout<<questionl;
	cin>>lname;
	message(fname, lname);
}

void message(char fname[], char lname[])
{
	char greeting[] = { 'H', 'e', 'l', 'l', 'o', ',',' ','\0' };
	cout << greeting <<fname<<" "<<lname<<"!"<<endl;
}
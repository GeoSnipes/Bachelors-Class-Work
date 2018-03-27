#include <iostream>
using namespace std;

void readnamey(char *);//char already is a bointer in itself
void readnamef(char *);
void displayname(char [], char []);

void main()
{
	//char name[30];
	char yname[20], fname[20];
	readnamey(yname);
	readnamef(fname);
	//cout<<yname<<" is a good friend of "<<fname<<endl;
	displayname(yname, fname);
}

void readnamey(char *name)
{
	cout<<"What is your name:"<<endl;
	cin>>name;//dont return because char is already being pointed to
}

void readnamef(char *name)
{
	cout<<"\nWhat is your friend's name:"<<endl;
	cin>>name;
}

void displayname(char pyname[], char pfname[])
{
	cout<<endl<<endl<<pyname<<" is a good friend of "<<pfname<<endl;
}
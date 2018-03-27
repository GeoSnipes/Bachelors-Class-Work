/*Problem 1
Problem 1:

Write a code that calculates 1*1+2*2-3*3+4*4-5*5+...+100*100*/
/*#include<iostream>
using namespace std;

void main()
{
	int x=2, sum=1;
	while(x<=100)
	{
		cout<<x;
		sum=sum+(x^2)-(x+1)^2;
		x=x+2;
	}
	cout<<sum;
	cout<<endl;
}*/
/*
Problem 2:

Declare a class Book. Add book title, author, year, number of pages. 
Add appropriate constructors and destructors (at least two of each).*/
/*#include<iostream>
#include<string>
using namespace std;

class Book
{
private:
	string bktitle;
	string author;
	int year;
	int numpgs;
public:
	Book();
	Book(string, string, int, int);
};

Book::Book()
{
	bktitle="N/A";
	author="N/A";
	year=0;
	numpgs=0;
}

Book::Book(string newBKtitle, string newAuthor, int newYear, int newNumpgs)
{
	bktitle=newBKtitle;
	author=newAuthor;
	year=newYear;
	numpgs=newNumpgs;
}*/

/*Problem 3:

For the class Book, add method WeekendReader that returns true of the number of pages in the book is less than 200.*/
#include<iostream>
#include<string>
using namespace std;

class Book
{
private:
	string bktitle;
	string author;
	int year;
	int numpgs;
public:
	Book();
	Book(string, string, int, int);
	bool weekendreader();
};

Book::Book()
{
	bktitle="N/A";
	author="N/A";
	year=0;
	numpgs=0;
}

Book::Book(string newBKtitle, string newAuthor, int newYear, int newNumpgs)
{
	bktitle=newBKtitle;
	author=newAuthor;
	year=newYear;
	numpgs=newNumpgs;
}

bool Book::weekendreader()
{
	if (numpgs<200)
		return true;
}
#include<iostream>
#include<string>
#include<list>
using namespace std;

void main()
{
	list<string> teststring;
	cout <<"Size of list before is: "<<teststring.size() << endl << endl;
	teststring.push_back("a");
	teststring.push_back("b");
	teststring.push_back("c");
	teststring.push_back("d");
	for (list<string>::iterator i = teststring.begin(); i != teststring.end();i++)
	{
		cout << *i << endl;
	}
	cout << "\nSize of list before is: " << teststring.size() << endl;
}
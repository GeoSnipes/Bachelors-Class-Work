#include<list>
#include<iostream>
using namespace std;

template <class T>
void PrintList(const list<T> &ilist)
{
	list<T>::const_iterator i=ilist.begin();
	while (i!=ilist.end())
	{
		cout<<*i<<endl;
		i++;
	}
}

void main()
{
	list<int> list_of_ints;
	cout<<"Before insert\n";
	list_of_ints.push_back(1);
	list_of_ints.push_back(2);
	list_of_ints.push_back(4);
	PrintList(list_of_ints);
	
	cout<<"\n\n After insert\n";
	list<int>::iterator my_it;
	my_it=list_of_ints.end(); //point to the endi
	my_it--; //move one item to the left
	list_of_ints.insert(my_it,3);
	PrintList(list_of_ints);
	
	cout<<"\n\n After delete\n";
	list<int>::iterator deleteint;
	deleteint=list_of_ints.begin();
	list_of_ints.erase(deleteint); //delete a item
	PrintList(list_of_ints);
}
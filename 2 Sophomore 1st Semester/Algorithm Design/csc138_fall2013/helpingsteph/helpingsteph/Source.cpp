#include<iostream>
using namespace std;
/*
	Input- maximum room capacity and amount of people attending the meeting
	Output- Whether or not it is legal or illegal to keep the meeting. 
*/
void displayanswer(int, int);
void main()
{
	//variables
	int maxroomcap, pplattend;
	
	//algorithm
	cout<<"Enter the maximum room capacity:\t";
	cin>>maxroomcap;
	cout<<"Enter the number of people attending the meeting:\t";
	cin>>pplattend;
	displayanswer(maxroomcap, pplattend);
}

void displayanswer(int maxroomcap, int pplattend)
{
	int remain;
	if (pplattend<=maxroomcap)
	{
		cout<<"It is legal to  hold the meeting."<<endl;
	}
	else
	{
		remain=pplattend-maxroomcap;
		cout<<"It is illegal to hold the meeting. "<< remain<< " people must evacuate in order to meet fire safety regulations."<<endl;
	}
}
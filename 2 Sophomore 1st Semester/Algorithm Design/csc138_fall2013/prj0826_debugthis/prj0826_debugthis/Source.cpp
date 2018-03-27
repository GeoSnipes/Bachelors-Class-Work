#include <iostream>
using namespace std;

/*
Input: age and gender 
output: for men this number is 220 minus the person's age and for women subtracting age times .88 from 206 provides a more accurate norm
*/

double ComputeHR(char, int);

void main()
{
	//variables
	int age;
	double MaxHeartRate;
	char gender;

	//instructions
	cout<<"Allows the user to compute his/her normal maximum heart rate."<<endl;
	cout<<"Input the gender:";
	cin>>gender;
	cout<<"Input your age:";
	cin>>age;
	MaxHeartRate = ComputeHR(gender, age);
	cout<<"Your max normal heart rate is:" <<MaxHeartRate<<endl; 

}

double ComputeHR(char g, int a)
{
	double MaxHeartRate;
	if (toupper(g) == 'M')
		MaxHeartRate = 220 - a;
	else
		MaxHeartRate = 206 - .88*a;
	return MaxHeartRate;
}


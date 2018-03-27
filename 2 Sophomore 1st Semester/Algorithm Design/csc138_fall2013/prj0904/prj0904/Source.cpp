#include <iostream>
using namespace std;

/*
Input: age and gender 
output: for men this number is 220 minus the person's age and for women subtracting age 
		times .88 from 206 provides a more accurate norm
*/

double ComputeHR(char, int); //function where heart rate is computed

void main()
{
	//variables
	int age, checkg, checka; //age, to ckeck if gender is within the constraints, to check if age is withing the constraints 
	double MaxHeartRate;	//saves the value of the normal max heart rate
	char gender;			//gender
	char cont = 'Y';	
	
	//instructions
	cout<<"Allows the user to compute his/her normal maximum heart rate:"<<endl;
	while (toupper(cont) == 'Y')
	{
		do 
			{
				cout<<"Input the gender:";
				cin>>gender;
				checkg=1;
				if ((toupper(gender)!='M')&&(toupper(gender)!='F'))
				{
					cout<<"You inputed the wrong letter. M- Male and F- Female\n";
					checkg=0;
				}
			} while (checkg!=1);
			cout<<"Input your age:";
			cin>>age;
		MaxHeartRate = ComputeHR(gender, age);
		cout<<"\nYour max normal heart rate is:" <<MaxHeartRate<<endl; 
		cout<<"Continue? (Y/N): ";
		cin>>cont;
		cout<<endl<<endl;
	}
}

double ComputeHR(char g, int a)
{
	if (toupper(g) == 'M')
		return 220 - a;
	else
		return 206 - .88*a;
}
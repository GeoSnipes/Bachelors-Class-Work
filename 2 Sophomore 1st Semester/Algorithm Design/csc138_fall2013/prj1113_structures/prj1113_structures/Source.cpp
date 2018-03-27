#include<iostream>
#include<string>
using namespace std;

//define the struture
struct car
{
	string name;
	string make;
	string model;
	int year;
};

void readdetails(car &);
void displaydetails(car &);

void main()
{
	car GeoCar, DeonCar;
	cout<<"Input the information for Geovannni's car."<<endl;
	readdetails(GeoCar);
	cout<<"\nInput the information for Deon's car."<<endl;
	readdetails(DeonCar);
	cout<<"\n\nGeovanni's car ";
	displaydetails(GeoCar);
	cout<<"Deon's car ";
	displaydetails(DeonCar);
	cout<<endl<<endl;
}

void readdetails(car &personCar)
{
	cout<<"Make:\t";
	cin>>personCar.make;
	cout<<"Model:\t";
	cin>>personCar.model;
	cout<<"Year:\t";
	cin>>personCar.year;
}
	
void displaydetails(car &personCar)
{
	cout<<"is a "<<personCar.year<<" "<<personCar.make<<" "<<personCar.model<<endl;
}
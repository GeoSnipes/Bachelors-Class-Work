#include <iostream>
using namespace std;
/*
Input: - size and elements of an array
       - operation to perform (read, display, max, min, search etc...)
      
Output:- the result of the selected operation 
*/

//functions prototypes
void readArray(int);
void disArray(int);
void minArray(int);
void maxArray(int);
void searchArray(int);

//Global Variable
int myArray[100]; //can not return arrays,so had to find a work around

void main()
{
	//variables
	int size;
	char userAnswer;
	
	//Algorithm
	cout<<"Enter the size of the array (smaller than a 100):\t";
	cin>>size;
	do
	{
		cout<<"Select an operation:\n"
			<<"\t1. Read an array\n"
			<<"\t2. Display the array\n"
			<<"\t3. Find max of the array\n"
			<<"\t4. Find min of an array\n"
			<<"\t5. Search for an element in the array\n"
			<<"\t0. Quit\n\n"
			<<"Selection:\t";
		cin>>userAnswer;
		switch (userAnswer)
		{
			case '1':
				readArray(size);
				break;
			case '2':
				disArray(size);
				break;
			case '3':
				maxArray(size);
				break;
			case '4':
				minArray(size);
				break;
			case '5':
				searchArray(size);
				break;
			case '0':
				cout<<"Thank you for using this program. Goodbye!! :D"<<endl<<endl;
				break;
			default:
				cout<<"Error. You did not pick a number among 1 through 6. Select again";
				break;
		}
	} while (userAnswer!='0');
}

void readArray(int size)
{
	int x;
	cout<<"Enter "<<size<<" integer values:\n";
	for (x=0;x<size;x++)
	{
		
		cin>>myArray[x];
	}
	cout<<endl;
}

void disArray(int size)
{
	int x;
	for (x=0;x<size;x++)
	{
		cout<<myArray[x]<<endl;
	}
	cout<<endl;
}

void maxArray(int size)
{
	int x;
	double max=-9999999999;
	for (x=0;x<size;x++)
	{
		if (myArray[x]>max)
			max=myArray[x];
	}
	cout<<"Max value in the array is "<<max<<endl<<endl;
}

void minArray(int size)
{
	int x;
	double min=9999999999;
	for (x=0;x<size;x++)
	{
		if (myArray[x]<min)
			min=myArray[x];
	}
	cout<<"Min value in the array is "<<min<<endl<<endl;
}

void searchArray(int size)
{
	int x, searchval, found=0, place;
	cout<<"What value are you searching for:\t";
	cin>>searchval;
	for (x=0; x<size; x++)
	{
		if (myArray[x]==searchval)
		{
			found=1;
			place=x;
		}
	}
	if (found==1)
		cout<<"The number you were searching for was found, it is the "<<place+1<<" value entered.\n\n";
	else
		cout<<"The value you are looking for cannnot be found in the array.\n\n";
}
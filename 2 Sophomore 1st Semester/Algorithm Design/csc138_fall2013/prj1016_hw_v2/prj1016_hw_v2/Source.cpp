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
void revArray(int);
void minArray(int);
void maxArray(int);
void avgArray(int);
void sortArray(int);

//Global Variable
int myArray[100]; //functions have problems with returning array,so had to find a work around

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
			<<"\t1. Read an array of size "<<size<<"\n"
			<<"\t2. Display the array of size "<<size<<"\n"
			<<"\t3. Reverse the array\n"
			<<"\t4. Find max of the array\n"
			<<"\t5. Find min of the array\n"
			<<"\t6. Find the average of the arraySearch for an element in the array\n"
			<<"\t7. Sort array in increasing order\n"
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
				revArray(size);
				break;
			case '4':
				maxArray(size);
				break;
			case '5':
				minArray(size);
				break;
			case '6':
				avgArray(size);
				break;
			case '7':
				sortArray(size);
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

void revArray(int size)
{
	int revArray[100], x;
	for (x=0;x<size;x++)
	{
		revArray[size-1-x]=myArray[x];
	}
	for (x=0;x<100;x++)
	{
		myArray[x]=revArray[x];
	}
	disArray(size);
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

void avgArray(int size)
{
	int x, sum=0, avg;
	for (x=0; x<size; x++)
	{
		sum+=myArray[x];
	}
	avg=sum/size;
	cout<<"The average of the elements in the array is "<<avg<<".\n\n";
}

void sortArray(int size)
{
	int x, j, save;
	for(x=0;x<size;x++)
	{
		for(j=x+1;j<size;j++)
		{
			if (myArray[x]>myArray[j])
			{
				save=myArray[j];
				myArray[j]=myArray[x];
				myArray[x]=save;
			}
		}
	}
	disArray(size);
}
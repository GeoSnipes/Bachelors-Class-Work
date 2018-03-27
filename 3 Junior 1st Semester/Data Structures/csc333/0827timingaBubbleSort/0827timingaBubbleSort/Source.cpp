#include <iostream>
#include <time.h>
#include <ctime>
#include <fstream>
using namespace std;


void bubblesort(int Array[], int b)
{
	int temp;
	for (int i = 0; i < b; i++)
	{
		for (int k = 0; k<b-1; k++)
		{
			if (Array[k]>Array[k + 1])
			{
				temp= Array[k+1];
				Array[k+1]=Array[k];
				Array[k]=temp;
			}
		}
	}
}

void main()
{
	int a, b, arrsize = 10001;
	double swatch;
	int Array[10001];
	clock_t startClock, finishClock;
	
	srand(time(NULL));
	for (a = 0; a<arrsize; a++)
	{
		Array[a] = rand();
	}
	ofstream time;
	time.open("BuubleSort Time.csv");
	time<<"Array Size"<<","<<"Time Taken (s)"<< endl;
	cout << "Array Size\t\tTime Taken (s)" << endl;
	for (b = 0; b<arrsize; b+=100)
	{
		startClock = clock();
		bubblesort(Array, b);
		finishClock = clock();
		swatch=(finishClock - startClock) / 100.0000000000;
		cout<<b<<"\t\t"<<swatch<<endl;
		time<<"'"<<b<<","<<swatch<<endl;
	}
	time.close();
}

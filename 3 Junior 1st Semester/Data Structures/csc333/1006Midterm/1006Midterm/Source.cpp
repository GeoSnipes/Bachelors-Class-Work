#include<iostream>
#include<ctime>
#include<time.h>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

/*
void frag1(int N){
	int sum;
	for (int i = 0; i<N; i++){
		if (rand() % 2 != 0){
			for (int j = 0; j < i; j++){
				sum=sum+1;
			}
		}
	}
}

void frag2(int N)
{
	int sum;
	for (int i = 0; i<N; i++){
		for (int j = 0; j < i; j *= 2){
			sum=sum+1;
		}
	}
}


void main()
{
	clock_t startclock, finishclock;
	long elapsed;
	ofstream result;
	result.open("Run Time Results.csv");
	for (int n = 0; n <= 1000; n += 40)
	{
		startclock = clock();
		frag1(n);
		finishclock = clock();
		elapsed = finishclock - startclock;
		result << n << "," << elapsed << endl;
		cout << n << "   \t" << elapsed << endl << endl;
	}
	result.close();
}*/

void main()
{
	vector<string> midt;
	midt.push_back("First");
	midt.push_back("Second");
	midt.push_back("Third");
	midt.push_back("Fourth");
	for (vector<string>::iterator i = midt.begin(); i <= midt.end(); i++)
	{
		cout << *i << endl;
	}

}
















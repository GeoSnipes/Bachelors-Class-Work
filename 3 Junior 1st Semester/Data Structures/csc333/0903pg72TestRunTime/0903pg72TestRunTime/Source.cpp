#include<iostream>
#include<ctime>
#include<time.h>
#include<fstream>
using namespace std;

void frag1(int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		++sum;
	}
}

void frag2(int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			++sum;
		}
	}
}

void frag3(int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n*n; ++j)
		{
			++sum;
		}
	}
}

void frag4(int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			++sum;
		}
	}
}

void frag5(int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i * i; ++j)
		{
			for (int k = 0; k < j; ++k)
			{
				++sum;
			}
		}
	}
}

void frag6(int n)
{
	int sum = 0, j;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < i * i; ++j)
		{
			if (j % i == 0)
			{
				for (int k = 0; k < j; ++k)
				{
					++sum;
				}

			}
		}
	}
}

void main()
{
	clock_t startclock, finishclock;
	long elapsed;
	ofstream result;
	result.open("Run Time Results.csv");
	for (int n = 0; n <= 300; n += 20)
	{
		startclock = clock();
		frag6(n);
		finishclock = clock();
		elapsed = finishclock - startclock;
		result << n << "," << elapsed<<endl;
		cout << n<< "   \t" <<elapsed << endl << endl;
	}
	result.close();
}
#include<fstream>
#include<iostream>
#include <ctime>
#include <time.h>
#include <unordered_map>
#include<map>
using namespace std;

template<class A>
void buildUNORMap(unordered_map<int, A> &egmap, int n)
{
	for (int i = 0; i < n; i++)
		egmap[i] = rand() %n;
}

template<class A>
void buildORMap(map<int, A> &egmap, int n)
{
	for (int i = 0; i < n; i++)
		egmap[i] = rand() %n;
}

void main()
{
	unordered_map<int, int> unormap;
	map<int, int> ormap;
	clock_t sclock, fclock;
	ofstream result;
	result.open("Map Timing.csv");
	int n;
	long unorelapsed, orelapsed;
	int random;
	result << "N"<<","<<"Unordered Map" << "," << "Tree" << endl;
	for (n = 1000; n<30000; n += 1000)
	{
		buildUNORMap(unormap, n);
		buildORMap(ormap, n);
		
		random = rand() %n;
		sclock = clock();
		for (int m = 0; m < 100000; m++)
			int check= unormap[random];
		fclock = clock();
		unorelapsed = fclock - sclock;

		sclock = clock();
		for (int m = 0; m < 100000; m++)
			int check= ormap[random];
		fclock = clock();
		orelapsed = fclock - sclock;
		result << n << "," << unorelapsed << "," << orelapsed << endl;
		
	}
	result.close();
}
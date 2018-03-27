#include<iostream>
#include<vector>
using namespace std;

void main()
{
	vector<int> integers;
	for (int i = 1; i <= 5; i++)
		integers.push_back(i);
	for (int k=0; k<integers.size(); k++)
	{
		cout << integers[k]<< endl;
	}
}
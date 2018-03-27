#include<iostream>
#include<queue>
using namespace std;

void main()
{
	queue<int> integers;
	integers.push(1);
	for (int i = 2; i <= 5; i++)
		integers.push(i);
	while (!integers.empty())
	{
		cout << integers.front() << endl;
		integers.pop();
	}
}
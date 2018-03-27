#include<iostream>
#include<stack>
using namespace std;

void main()
{
	stack<int> integers;
	for (int i = 1; i <= 5; i++)
		integers.push(i);
	//for (stack<int>::iterator iter = intergers.begin(); iter != integers.end(); iter++) will not work for stacks
	while (!integers.empty())
	{
		cout << integers.top() << endl;
		integers.pop();
	}
}
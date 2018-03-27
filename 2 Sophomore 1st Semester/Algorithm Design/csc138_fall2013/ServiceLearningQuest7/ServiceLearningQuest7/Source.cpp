#include <iostream>
using namespace std;

char mystery(int firstParameter, int secondParameter);

int main()
{
	cout<<mystery(10,9)<<"ow\n";
	return 0;
}

char mystery(int firstParameter, int secondParameter)
{
	if (firstParameter>=secondParameter)
		return 'W';
	else 
		return 'H';
}
#include <iostream>
using namespace std;

int calculate(char, int);

void main()
{
	//variables
	int t;
	char s;
	

	//instructions
	cout<<"What size pizza do you want?-small='1', medium='2', and large='3'"<<endl;
	cin>>s;
	cout<<"How many extra toppings do you want?"<<endl;
	cin>>t;
	cout<<"Your total is "<<calculate(s,t)<<endl;
}
int calculate(char s, int t)
{
	int total, ans;
	total=t*2;	
	if (s=='1')
	{
		ans=5+total;
	}
	else if (s=='2')
	{
			ans=7+total;
	}
	else if (s=='3')
	{
			ans=10+total;
	}
	return ans;
}				
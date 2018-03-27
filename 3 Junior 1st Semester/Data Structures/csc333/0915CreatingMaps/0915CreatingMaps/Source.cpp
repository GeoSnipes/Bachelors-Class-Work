#include<iostream>
#include<map>
#include<string>
using namespace std;

void main()
{
	map<int, string> egmap;
	egmap[0] = "My string 0";
	egmap[1] = "My string 1";
	cout << egmap[0] << endl;
	cout << egmap[1] << endl;

	map<string, string> egmaps;
	egmaps["list"] = "My string list";
	egmaps["vector"] = "My string vector";
	cout << egmaps["list"] << endl;
	cout << egmaps["vector"] << endl;
}
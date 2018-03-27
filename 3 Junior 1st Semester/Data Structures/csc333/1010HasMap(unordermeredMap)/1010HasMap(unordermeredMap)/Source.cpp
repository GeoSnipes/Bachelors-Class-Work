#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;
/*
class Cars
{
	string make, model;
	Cars(string newmake, string newmodel){ make = newmake; model = newmodel; }
};*/

void main()
{
	unordered_map<string, int> my_map;
	my_map["John Doe"] = 30;
	my_map["Jane Doe"] = 75;

	string StudentName = "Jane Doe";
	if (my_map.find(StudentName) != my_map.end())
	{
		cout << my_map[StudentName] << endl;
	}
	else
		cout << "The key is not found" << endl;


	unordered_map<string, pair<int, string>>cars_map;
	cars_map["Jane Doe"] = make_pair(1, "Cayenne");
	
	StudentName = "Jane Doe";
	if (cars_map.find(StudentName) != cars_map.end())
	{
		cars_map[StudentName].first++;
		cout << "Make: " << cars_map[StudentName].first << endl;
		cout << "Model:"<<cars_map[StudentName].second << endl;
	}
	else
		cout << "The key is not found" << endl;

	//unordered_map<string, pair<string, Cars>> cars_map2;
}
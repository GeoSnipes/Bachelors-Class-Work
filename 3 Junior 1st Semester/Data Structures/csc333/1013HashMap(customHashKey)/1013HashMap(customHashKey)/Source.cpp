#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Person
{
public:
	Person(string newFirstName, string newLastName)
	{
		firstName = newFirstName;
		lastName = newLastName;
	}

	bool operator==(const Person &p) const
	{
		return((firstName == p.firstName) && (lastName == p.lastName));
	}

	string firstName;
	string lastName;
};

class PersonKey
{
public:
	size_t operator()(const Person &p) const
	{
		return hash<string>()(p.firstName) ^ hash<string>()(p.lastName);//^- exclusive or
	}
};

void main()
{

	//testing making your own key
	hash<int> h_int;
	for (int i= 0; i < 10; i++)
	{
		cout << i << " hash code= " << h_int(i) << endl;
	}
	hash<string> h_str;
	cout <<"A hash code= " << h_str("A") << endl;//or
	cout <<"B hash code= " << hash<string>()("B") << endl;//string can be replaced with int or any other data type
	cout <<"C hash code= " << hash<string>()("C") << endl;

	//maing a key from class
	unordered_map<Person, float, PersonKey> grades;//class used as key, data type, class used to generate key
	Person p1("John", "Doe");
	cout << PersonKey()(p1) << endl;//or
	cout << PersonKey()(Person("Jane", "Doe"))<<endl;
	
	grades[Person("Jane", "Doe")] = 27;
	grades[Person("John", "Doe")] = 20;

	for (auto i : grades)
	{
		cout << endl << "Name:" << i.first.firstName << " " << i.first.lastName << " grades are " << i.second << endl;
	}

}

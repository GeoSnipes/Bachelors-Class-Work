#include<iostream>
#include<string>
#include<fstream>
using namespace std;
/*
Input: individual's name along with their position in the competition
Output: personalized message showing person's name and place. 
*/

void main()
{
	string name;
	int place;
	ifstream position;
	position.open("position.txt");
	if (position.is_open())
	{
		while (!position.eof())
			{
				getline(position, name, place);
				switch (place)
				{
					case 1:
						cout<<endl<<name<<" got first place.\n\n\n\n";
						break;
		case 2:
			cout<<endl<<name<<" got second place.\n\n\n\n";
			break;
		case 3:
			cout<<endl<<name<<" got third place.\n\n\n\n";
			break;
		case 4:
			cout<<endl<<name<<" got 4th place.\n\n\n\n";
			break;
		case 5:
			cout<<endl<<name<<" got 5th place.\n\n\n\n";
			break;
		case 6:
			cout<<endl<<name<<" got 6th place.\n\n\n\n";
			break;
		case 7:
			cout<<endl<<name<<" got 7th place.\n\n\n\n";
			break;
		case 8:
			cout<<endl<<name<<" got 8th place.\n\n\n\n";
			break;
		case 9:
			cout<<endl<<name<<" got 9th place.\n\n\n\n";
			break;
		case 10:
			cout<<endl<<name<<" got 10th place.\n\n\n\n";
			break;
		default:
			cout<<"You did not enter a place between 1 and 10.";
			break;
	}
}
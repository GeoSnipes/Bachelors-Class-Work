#include<iostream>
#include<fstream>

using namespace std;

int main() 
{
	ifstream myReadFile;
	myReadFile.open("text.txt");
	char output, check;
	if (myReadFile.is_open()) 
	{
		while (!myReadFile.eof()) 
		{
			myReadFile>>output;
			if (('A'<=output)&&(output<='Z'))
				cout<<"You entered the capital letter "<<output<<endl<<endl;
			else if (('a'<=output)&&(output<='z'))
				cout<<"You entered the common letter "<<output<<endl<<endl;
			else
				cout<<output<<" is not a character."<<endl<<endl;
		}
		
	}
	cout<<"\n\nSee you next time.\n\n\n";
	myReadFile.close();
	return 0;
}
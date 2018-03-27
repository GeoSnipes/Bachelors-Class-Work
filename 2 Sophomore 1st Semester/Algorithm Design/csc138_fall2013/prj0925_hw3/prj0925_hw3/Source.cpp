#include<iostream>
using namespace std;
/*
Input: A number
Output: Level game you will be playing with a little description of how hard it is
*/

void playGameLevel1();
void playGameLevel2();
void playGameLevel3();
void playGameLevel4();
void playGameLevel5();
 
int main()
{
  int input;
  char pchoice;
  do
  {
	  cout<<"0. Quit Game\n";
	  cout<<"1. Play game level 1\n";
	  cout<<"2. Play game level 2\n";
	  cout<<"3. Play game level 3\n";
	  cout<<"4. Play game level 4\n";
	  cout<<"5. Play game level 5\n";
	  cout<<"Selection: ";
	  cin>> input;
	  switch ( input )
	  {
		  case 0:
			  cout<<"\nCome back again next time. Good Bye.\n";
			  break;
		  case 1:
			  playGameLevel1();
			  cout<<"Thank you for playing!\n";
			  break;
		  case 2:
			  playGameLevel2();
			  cout<<"Thank you for playing!\n";
			  break;
		  case 3:
			  playGameLevel3();
			  cout<<"Thank you for playing!\n";
			  break;
		  case 4:
			  playGameLevel4();
			  cout<<"Thank you for playing!\n";
			  break;
		  case 5:
			  playGameLevel5();
			  cout<<"Thank you for playing!\n";
			  break;
		  default:
			  cout<<"Error, bad input, quitting\n";
			  break;
	  }
	  cout<<"\n\nDo you want to play again (y/n):\t";
	  cin>>pchoice;
  } while (toupper(pchoice)=='Y');
  cin.get(); //Forces the program to wait for a next input from the keyboard.
}
void playGameLevel1()
{
    cout << "Playing game level 1... This level is easy..........\n";
}
void playGameLevel2()
{
    cout << "Playing game level 2... This level is a little bit less easy..........\n";
}
void playGameLevel3()
{
    cout << "Playing game level 3... This level is moderate..........\n";
}
void playGameLevel4()
{
    cout << "Playing game level 4... This level is more difficult..........\n";
}
void playGameLevel5()
{
     cout << "Playing game level 5... This level is very difficult..........\n";
}

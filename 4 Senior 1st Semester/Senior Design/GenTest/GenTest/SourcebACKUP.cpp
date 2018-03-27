#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
using namespace std;

class Schedule{
public:
	Schedule();
	void createSch();
	void printSch();
	void mutation();	//randomly change a teacher's class
	Schedule operator +(const Schedule &s);
	int Fit();

private:
	vector<vector<bool> > teach1;
};

Schedule::Schedule(){
	createSch();
}

void Schedule::createSch(){
	int pos;	//which class should this teacher teach
	vector<bool>row(4);
	for (int x = 0; x<4; x++){
		teach1.push_back(row);
		pos = rand() % 4;
		teach1[x][pos] = 1;
	}
}

void Schedule::printSch(){
	for (int x = 0; x < 4; x++){
		for (int j = 0; j < 4; j++){
			cout << teach1[x][j] << " ";
		}
		cout << endl;
	}

}

void Schedule::mutation(){
	int changeX = rand() % 4, changeY = rand() % 4;
	//teach1[changeX][changeY] = !teach1[changeX][changeY];
	teach1[changeX][0] = 0;
	teach1[changeX][1] = 0;
	teach1[changeX][2] = 0;
	teach1[changeX][3] = 0;
	teach1[changeX][changeY] = 1;
}

class SchedulePool{
public:
	SchedulePool(int); // initialize with int # of random schedules
	int size(){ return pool.size(); }
	void printList();

private:
	list<Schedule> pool;
};

SchedulePool::SchedulePool(int x)
{
	for (int count = 0; count < x; count++){
		pool.push_back(Schedule());
	}
}

void SchedulePool::printList(){
	typedef list<Schedule>::iterator ele1;
	for (ele1 i = pool.begin(); i != pool.end(); ++i) /* Prefer pre-increment with iterators */
	{
		i->printSch();
		cout << endl << endl;
	}

}

void SchedulePool::mutate(int x)
{}

int main()
{
	srand(time(NULL));
	Schedule teachsch;
	teachsch.printSch();
	teachsch.mutation();
	cout << endl << endl;
	teachsch.printSch();
	SchedulePool list(10);
	list.printList();
	cout << list.size();
	cin.get();
	return 0;
}


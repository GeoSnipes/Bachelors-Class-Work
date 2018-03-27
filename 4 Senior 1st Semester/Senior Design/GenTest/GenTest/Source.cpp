#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

/*vector<vector<int> > teachres();
vector<vector<int> > teachres(){
	srand(time(NULL));
	vector<vector<int> >tres(6, vector<int>(6));//saves the teachers reponce of how likely they want to teacha subject.
	for (int y = 0; y<tres[0].size(); y++){
		for (int x = 0; x<tres.size(); x++)
			tres[x][y] = rand() % 51; //change on final to cin>>teacher teaches this class
	}
	return tres;
}
vector<vector<int> > teachsur = teachres();*/

vector<vector<int> > teachres();
vector<vector<int> > teachres(){
	vector<vector<int> >tres(5, vector<int>(5));//saves the teachers reponce of how likely they want to teacha subject.
	tres[0][0] =89 ;
	tres[0][1] =46 ;
	tres[0][2] =53 ;
	tres[0][3] =0 ;
	tres[0][4] =40 ;
	tres[1][0] =87 ;
	tres[1][1] =72 ;
	tres[1][2] =29 ;
	tres[1][3] =65;
	tres[1][4] =95 ;
	tres[2][0] =17 ;
	tres[2][1] =3 ;
	tres[2][2] =94 ;
	tres[2][3] =29 ;
	tres[2][4] =73 ;
	tres[3][0] =43 ;
	tres[3][1] =46 ;
	tres[3][2] =59 ;
	tres[3][3] =29 ;
	tres[3][4] =26 ;
	tres[4][0] =40 ;
	tres[4][1] =92 ;
	tres[4][2] =76 ;
	tres[4][3] =84 ;
	tres[4][4] =47 ;
	return tres;
}
vector<vector<int> > teachsur = teachres();

class Schedule{
public:
	Schedule();
	Schedule(const vector < vector<int> > &);
	Schedule(const Schedule &); // copy constructor
	Schedule(const Schedule &, const Schedule &); // combinatorial constructor
	Schedule operator +(const Schedule &s);
	void printSch();
	void mutation();	//randomly change a teacher's class
	int calcFit(const vector< vector<int> > &);
	void setFit(int);
	int getFit();

private:
	vector< vector<bool> > classvteach;
	int fit;
};

Schedule::Schedule(){
	int pos;	//which class should this teacher teach
	vector<bool>row(teachsur[0].size());
	for (int x = 0; x < teachsur.size(); x++){
		classvteach.push_back(row);
		pos = rand() % classvteach[0].size();
		classvteach[x][pos] = 1;
	}
}

Schedule::Schedule(const vector< vector<int> > &vec){
	int pos;	//which class should this teacher teach
	vector<bool>row(vec[0].size());
	for (int x = 0; x < vec.size(); x++){
		classvteach.push_back(row);
		pos = rand() % classvteach[0].size();
		classvteach[x][pos] = 1;
	}
	fit = calcFit(vec);
}

Schedule::Schedule(const Schedule &q)
{
	classvteach = q.classvteach;
	fit = q.fit;
}

Schedule::Schedule(const Schedule &q, const Schedule &w){
	int count = 0, x;
	classvteach = q.classvteach;
	while (count <= classvteach.size() / 2)
	{
		x = rand() % classvteach.size();
		for (int y = 0; y < classvteach[0].size(); y++)
		{
			classvteach[x][y] = w.classvteach[x][y];
		}
		count++;
	}
	fit = calcFit(teachsur);
}

void Schedule::printSch(){
	for (int x = 0; x < classvteach.size(); x++){
		for (int j = 0; j < classvteach[0].size(); j++){
			cout << classvteach[x][j] << " ";
		}
		cout << endl;
	}
	cout << "Fitness= " << getFit() << endl << endl;
}

void Schedule::mutation(){
	int changeY = rand() % classvteach.size(), changeX = rand() % classvteach[0].size();
	for (int x = 0; x < classvteach[0].size(); x++)
	{
		classvteach[changeY][x] = 0;
	}
	classvteach[changeY][changeX] = 1;
	setFit(calcFit(teachsur));
}

int Schedule::calcFit(const vector< vector<int> > &vec){
	int fitT = 0;
	for (int x = 0; x < classvteach.size(); x++){
		for (int y = 0; y < classvteach[0].size(); y++)
		{
			if (classvteach[x][y] == 1)
				fitT += vec[x][y];
		}
	}
	return fitT;
}

void Schedule::setFit(int x)
{
	fit = x;
}

int Schedule::getFit()
{
	return fit;
}

class SchedulePool{
public:
	SchedulePool(int, const vector<vector<int> > &); // initialize with int # of random schedules
	int size(){ return pool.size(); }
	void printList();
	void mutate(int);
	void crossBreedSP(int);
	void quickSort(int, int);
	void optimalSch(int);
	void eraseWorst(){ pool.erase(pool.begin()); pool.erase(pool.begin()); };
private:
	vector<Schedule> pool;
};

SchedulePool::SchedulePool(int x, const vector<vector<int> > &vec)
{
	for (int count = 0; count < x; count++){
		pool.push_back(Schedule(vec));
	}
}

void SchedulePool::printList(){
	typedef vector<Schedule>::iterator ele1;
	ele1 i = pool.end() - 1;
	while (i != pool.end()){
		i->printSch();
		cout << endl << endl;
		i++;
	}
	/*for (int x = 0; x < teachsur.size(); x++){
		for (int j = 0; j < teachsur[0].size(); j++){
			cout << teachsur[x][j] << " ";
		}
		cout << endl;
	}*/
}

void SchedulePool::mutate(int x)
{
	Schedule newVec;
	for (int y = 0; y < x; y++)
	{
			newVec = pool[rand() % pool.size()];
			newVec.mutation();
			pool.push_back(newVec);
	}
}

void SchedulePool::crossBreedSP(int q)
{
	for (int x = 0; x < q; x++)
	{
		Schedule newVec(pool[rand() % pool.size()], pool[rand() % pool.size()]);
		pool.push_back(newVec);
	}
}

void SchedulePool::quickSort(int left, int right) {
	int i = left, j = right;
	Schedule tmp;
	int pivot = pool[(left + right) / 2].getFit();

	/* partition */
	while (i <= j) {
		while (pool[i].getFit() < pivot)
			i++;
		while (pool[j].getFit() > pivot)
			j--;
		if (i <= j) {
			tmp = pool[i];
			pool[i] = pool[j];
			pool[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(left, j);
	if (i < right)
		quickSort(i, right);
}

void SchedulePool::optimalSch(int x)
{
	int chequart = 1, quart = pool.size() / 4;
	for (int n = 0; n < x; n++)
	{
		crossBreedSP(3);
		mutate(3);
		if (n == quart*chequart)
		{
			quart = pool.size() / 4;
			quickSort(0, pool.size() - 1);
			chequart++;
			pool.erase(pool.begin(), pool.begin() + quart);
		}
	}
}

int main()
{
	srand(time(NULL));
	SchedulePool list(100, teachsur);
	list.quickSort(0, list.size() - 1);
	list.optimalSch(100);
	list.quickSort(0, list.size() - 1);
	list.printList();
	system("PAUSE");
	return 0;
}
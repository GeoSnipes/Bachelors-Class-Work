#include<list>
class Schedule{
public:
	Schedule(); // random schedule;
	Schedule(const Schedule &); // copy constructor
	Schedule(const Schedule &, const Schedule &); // combinatorial constructor
	void Mutation(); // randomly change smth
	int virtual Fit() = 0; // the "fitness" of the schedule
	bool operator >(const Schedule &s){
		return Fit() > s.Fit();
	}
	bool operator <(const Schedule &s){
		return Fit() < s.Fit();
	}
private:
	// matrix?
};


class FacultySchedule : public Schedule{
public:
	int Fit(); // the implementation of the fitness.
};


class SchedulePool{
public:
	SchedulePool(int); // initialize with int random schedules
	SchedulePool();
	void KillNWorst(int); // sort the pool and erase int worst schedules
	void MutateN(int); // apply mutation to int schedules
	void AddCombinations(int); // add int combinatorial schedules
	void RunAlgorithm(int, int, list<Schedule> &);
	// run the algorithm for int generations
	// and return int best schedules
private:
	list<Schedule> pool;
};


SchedulePool::SchedulePool(int N){
	for (int i = 0; i < N; i++){
		pool.push_back(Schedule());
	}
}


void SchedulePool::RunAlgorithm(int G, int N, list<Schedule> &l){
	for (int i = 0; i < G; i++){
		KillNWorst(? );
		MutateN(? );
		AddCombinations(? );
	}
	sort(pool.begin(), pool.end(), [](Schedule s1, Schedule s2){
		return s1 > s2;
	});
	// add the top N schedules to list l
}


void main(){
	SchedulePool sp(1000);
	list<Schedule> s_list;
	sp.RunAlgorithm(1000, 2, s_list);
}
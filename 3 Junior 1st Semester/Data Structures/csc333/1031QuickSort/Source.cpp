#include<iostream>
#include<vector>
using namespace std;

int c;
void Swap(int &s1, int &s2)
{
	int buff = s2;
	s2 = s1;
	s1 = buff;
}
template<class T>
void Partition(vector<T> &v, int Left, int Right, int &PivotIndex){
	T Pivot = v[PivotIndex];
	swap(v[PivotIndex], v[Right]);
	for (int i = Left; i <= Right; i++){
		if (v[i] < Pivot){
			Swap(v[i], v[PivotIndex]);
			PivotIndex++;
		}
	}
	Swap(v[Right], v[PivotIndex]);
	c++;
}
template<class T>
void QuickSort(vector<T> &v, int Left, int Right){
	if (Left >= Right) return;
	int PivotIndex = Left;
	Partition(v, Left, Right, PivotIndex);
	QuickSort(v, Left, PivotIndex - 1);
	QuickSort(v, PivotIndex + 1, Right);
}
template<class T>
void QuickSort(vector<T> &v){
	QuickSort(v, 0, v.size() - 1);
}

void main()
{
	vector<int> v;
/*	for (int i = 0; i<10; i++)
	{
		v.push_back(rand() % 100);
	}*/
	v.push_back(1);
	v.push_back(8);
	v.push_back(5);
	v.push_back(3);
	v.push_back(0);
	v.push_back(7);
	v.push_back(9);
	v.push_back(2);
	QuickSort(v);
	for (int i = 0; i<v.size() - 1; i++)
	{
		cout << v[i] << endl;
	}
	cout << c;
}
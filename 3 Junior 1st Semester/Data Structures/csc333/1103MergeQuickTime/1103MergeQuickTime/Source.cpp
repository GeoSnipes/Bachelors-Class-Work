#include<vector>
#include<iostream>
#include<ctime>
#include<time.h>
using namespace std;

template <class Q>
void populateVector(vector<Q> &v, int n)
{
	for (int i = 0; i < n; i++)
	{
		v.push_back((float)(rand() % 1000000));
	}
}

void Swap(float &s1, float &s2)
{
	float buff = s2;
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

template<class T>
void Merge(vector<T> &v, int left, int middle, int right){
	vector<T> result;
	int i = left;
	int j = middle + 1;
	while (i <= middle && j <= right){
		if (v[i] < v[j]){
			result.push_back(v[i++]);
		}
		else{
			result.push_back(v[j++]);
		}
	}
	while (i <= middle){
		result.push_back(v[i++]);
	}
	while (j <= right){
		result.push_back(v[j++]);
	}
	for (int i = left; i <= right; i++)
		v[i] = result[i - left];
}
template<class T>
void MergeSort(vector<T> &v, int left, int right){
	if (left >= right) return;
	int middle = (left + right) / 2;
	MergeSort(v, left, middle);
	MergeSort(v, middle + 1, right);
	Merge(v, left, middle, right);
}
template<class T>
void MergeSort(vector<T> &v){
	MergeSort(v, 0, v.size() - 1);
}

void main()
{
	float elapsed;
	clock_t sclock, fclock;

	vector<float> a;
	populateVector(a, 100000);
	sclock = clock();
	QuickSort(a);
	fclock = clock();
	elapsed = fclock - sclock;
	cout << "Quicksort takes " << elapsed << " clock time to complete.\n";

	
	vector<float> b;
	populateVector(b, 100000);
	sclock = clock();
	MergeSort(b);
	fclock = clock();
	elapsed = fclock - sclock;
	cout << "Mergesort takes " << elapsed << " clock time to complete.\n";
}
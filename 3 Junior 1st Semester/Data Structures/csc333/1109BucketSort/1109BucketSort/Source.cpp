#include <iostream>
#include <vector>
using namespace std;

void BucketSort(vector<int>&v){
	int MaxBucket = 10;
	vector<int> Bucket(MaxBucket, 0);
	for (int i = 0; i<v.size(); i++){
		Bucket[v[i]]++;
	}
	v.clear();
	for (int i = 0; i<Bucket.size(); i++)
	{
		for (int j = 0; j<Bucket[i]; j++)
		{
			v.push_back(i);
		}
	}
}

void main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(8);
	v.push_back(5);
	v.push_back(3);
	v.push_back(0);
	v.push_back(7);
	v.push_back(9);
	v.push_back(2);

	BucketSort(v);
	for (int i = 0; i<v.size(); i++){
		cout << v[i] << " ";
	}
}
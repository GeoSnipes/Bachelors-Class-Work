#include<iostream>
#include<vector>

using namespace std;
int c = 0;
template<class T>
void Merge(vector<T> &v, int left, int middle, int right)
{
	c++;
	vector<T> result;
        int i = left;
        int j = middle+1;
        while(i <= middle && j <= right){
                if(v[i] < v[j]){
                        result.push_back(v[i++]);
                }
                else{
                        result.push_back(v[j++]);
                }
        }
        while(i <= middle){
                result.push_back(v[i++]);
        }
        while(j <= right){
                result.push_back(v[j++]);
        }
        for(int i = left; i <= right; i++)
                v[i] = result[i-left];
}
template<class T>
void MergeSort(vector<T> &v, int left, int right){
        if(left >= right) return;
        int middle = (left+right)/2;
        MergeSort(v, left, middle);
        MergeSort(v, middle+1, right);
        Merge(v, left, middle, right);
}
template<class T>
void MergeSort(vector<T> &v){
        MergeSort(v, 0, v.size()-1);
}
void main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(8);
	v.push_back(5);
	v.push_back(3);
	v.push_back(0);
	v.push_back(7);
	v.push_back(9);
	v.push_back(2);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout<<endl;
	MergeSort(v);
	for (int i = 0; i<v.size(); i++)
	{
		cout << v[i] <<" ";
	}
	cout <<endl<< c;
}
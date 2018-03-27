#include<vector>
#include<iostream>
template<class T>
void Swap(T &x, T &y){
	T Buff = x;
	x = y;
	y = Buff;
}
template<class T>
class Heap{
public:
	void Insert(const T &Data);
	void Extract(T &Data);
private:
	std::vector<T> _data;
	void BubbleUp(int pos);
	void BubbleDown(int pos);
	int MinIndex(int pos1, int pos2) const;
};
template<class T>
void Heap<T>::Insert(const T &Data){
	_data.push_back(Data);
	BubbleUp(_data.size() - 1);
}
template<class T>
void Heap<T>::Extract(T &Data){
	Data = _data[0];
	_data[0] = _data[_data.size() - 1];
	_data.pop_back();
	BubbleDown(0);
}
template<class T>
void Heap<T>::BubbleUp(int pos){
	if (pos == 0) 
		return;
	int parent = (pos + 1) / 2 - 1;
	if (_data[pos] < _data[parent])
	{
		Swap(_data[pos], _data[parent]);
		BubbleUp(parent);
	}
}
template<class T>
void Heap<T>::BubbleDown(int pos){
	if (pos + 1 >= _data.size()) 
		return;
	int child1 = (pos + 1) * 2 - 1;
	int child2 = (pos + 1) * 2 - 1 + 1;
	int min_index = MinIndex(pos, MinIndex(child1, child2));
	if (min_index == pos) 
		return;
	Swap(_data[pos], _data[min_index]);
	BubbleDown(min_index);
}

template<class T>
int Heap<T>::MinIndex(int pos1, int pos2) const{
	if (pos1 >= _data.size() && pos2 >= _data.size()) 
		return -1;
	if (pos1 >= _data.size() || pos1 < 0) 
		return pos2;
	if (pos2 >= _data.size() || pos2 < 0) 
		return pos1;
	return _data[pos1] < _data[pos2] ? pos1 : pos2;
}

void main(){
	Heap<int> h;
	for (int i = 0; i < 1000; i++){
		h.Insert(rand() % 1000);
	}
	for (int i = 0; i < 1000; i++){
		int A;
		h.Extract(A);
		std::cout << A << std::endl;
	}
}
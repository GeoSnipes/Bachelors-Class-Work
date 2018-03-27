#include<iostream>
using namespace std;

class BinaryMinHeap {
private:
	int *data;
	int heapSize;
	int arraySize;

	int getLeftChildIndex(int nodeIndex) {
		return 2 * nodeIndex + 1;
	}

	int getRightChildIndex(int nodeIndex) {
		return 2 * nodeIndex + 2;
	}

	int getParentIndex(int nodeIndex) {
		return (nodeIndex - 1) / 2;
	}

public:
	BinaryMinHeap(int size) {
		data = new int[size];
		heapSize = 0;
		arraySize = size;
	}

	int getMinimum() {
		if (isEmpty())
			throw string("Heap is empty");
		else
			return data[0];
	}

	bool isEmpty() {
		return (heapSize == 0);
	}

	~BinaryMinHeap() {
		delete[] data;
	}

	void siftUp(int);
	void insert(int);
};

void BinaryMinHeap::siftUp(int nodeIndex) {
	int parentIndex, tmp;
	if (nodeIndex != 0) {
		parentIndex = getParentIndex(nodeIndex);
		if (data[parentIndex] > data[nodeIndex]) {
			tmp = data[parentIndex];
			data[parentIndex] = data[nodeIndex];
			data[nodeIndex] = tmp;
			siftUp(parentIndex);
		}
	}
}

void BinaryMinHeap::insert(int value) {
	if (heapSize == arraySize)
		throw string("Heap's underlying storage is overflow");
	else {
		heapSize++;
		data[heapSize - 1] = value;
		siftUp(heapSize - 1);
	}
}

void main(){}
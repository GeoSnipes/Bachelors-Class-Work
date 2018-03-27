#include<string>
#include<iostream>
using namespace std;

template <class T>
struct Node
{
	T _data;
	Node<T> *left;
	Node<T> *right;
};

template <class T>
void addNode(Node<T> *&n, T data)
{
	if (n == 0)
	{
		n = new Node<T>;
		n->_data = data;
		n->left = n->right = 0;
		return;
	}
	if (data > n->_data)
		addNode(n->right, data);
	else
		addNode(n->left, data);
}

template <class T>
Node<T> *Search(Node<T> *&n, T Data)
{
	if (n = 0)
		return n;
	if (Data> n->_data)
		return Search(n->_right, Data);
	else
		return Search(n->_left, Data);
}

template <class T>
void printTreePreOrder(Node<T> *&n)
{
	if (n == 0)
		return;
	printTreePreOrder(n->left);
	cout << n->_data << endl;
	printTreePreOrder(n->right);
}

void main()
{
	Node<int> *root;
	root = 0;
	for (int i = 0; i < 10; i++)
	{
		addNode(root, rand() % 1000);
	}
	printTreePreOrder(root);
}
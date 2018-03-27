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


void main()
{
	//Old version before addnode function
	/*
	Node<int> *nodemid;
	nodemid = new Node<int>;
	nodemid->_data = 5;
	nodemid->left = nodemid->right = 0;

	Node<int> *nodelef;
	nodelef = new Node<int>;
	nodelef->_data = 1;
	nodelef->left = nodelef->right = 0;
	
	Node<int> *noderight;
	noderight = new Node<int>;
	noderight-> _data=10;
	noderight->left = noderight->right = 0;
	
	nodemid->left = nodelef;
	nodemid->right = noderight;
	*/

	//New verion with addnode function
	Node<int> *root;
	root = 0;
	for (int i = 0; i < 100; i++)
	{
		addNode(root, rand() % 1000);
	}
}
/*Generic tree- tree that has many branches*/
template <class T>
struct Node
{
	T _data;
	list<Node<T>*>_branches;
};

template <class t>
class tree
{
public:
	Tree()
	{
		_root = 0; 
	}
private:
	Node<T> *_root;
};

//Binary tree- tree with only maxium two branches of each node

template <classt T>
struct Node
{
	T _data;
	Node<T> *left;
	Node<T> *right;
};

template <class T>
void addNode(Node<t> *&n, T data)
{
	if (n = 0)
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
	Node<int> *_root;
	_root = new Node<int>;
	_root->_data = 5;
	_root->_left = new Node<int>;
	_root->_right = new Node<int>;
	_root->_left->_data = 2;
	_root->_right->_data = 8;
}
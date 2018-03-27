#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

struct Node{
	string _name;
	vector<pair<Node *, int>> _edges;
};

class Graph{
public:
	void AddNode(string);
	void AddEdge(string, string, int);
private:
	map<string, Node *> _nodes;
};

void Graph::AddNode(string Name)
{
	Node *n = new Node;
	n->_name = Name;
	_nodes[Name] = n;
}

void Graph::AddEdge(string From, string To, int weight)
{
	Node *from = _nodes[From];
	Node *to = _nodes[To];
	from->_edges.push_back(make_pair(to, weight));

}

void main()
{
	Graph g;
	g.AddNode("q");
	g.AddNode("e");
	g.AddNode("a");

	g.AddEdge("e", "q", 5);
	g.AddEdge("q", "e", 6);
}
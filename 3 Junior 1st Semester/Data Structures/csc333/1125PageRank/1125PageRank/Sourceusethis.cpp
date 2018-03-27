/*
Create a graph of at least 6 nodes. Your graph can be based on
cities/roads, classes/prerequisites, webpages/links, etc.
Important: your graph has to be realistic! Use actual cities and roads with
actual mileage, or actual classes and prerequisites (unweighted graph), or
actual webpages and links, etc.

Submission format:
1. Screenshot of your graph code
2. Screenshot of compilation screen, i.e. no errors in the program
3. Screenshot of topological sort of your graph
*/

#include<map>
#include<queue>
#include<string>
#include<iostream>
#include<vector>
#include<list>
using namespace std;
struct Node{
public:
	string _name;
	list<pair<Node *, int>> _edges;
};
class Graph{
public:
	Graph(const Graph &);
	Graph();
	~Graph();
	void AddNode(string);
	void AddEdge(string, string, int);
	void DeleteNode(string);
	void DeleteEdge(string, string);
	void DeleteAllInEdges(string);
	int InDegree(string);
	void PageRank(float d);
	void PrintSortOrder();
private:
	map<string, Node *> _nodes;
};
Graph::Graph(const Graph &g){
	for (auto n : g._nodes){
		AddNode(n.first);
	}
	for (auto n : g._nodes){
		for (auto e : n.second->_edges){
			AddEdge(n.first, e.first->_name, e.second);
		}
	}
}
Graph::Graph(){}
Graph::~Graph(){
	for (auto n : _nodes){
		DeleteNode(n.first);
	}
}
void Graph::AddNode(string Name){
	Node *n = new Node;
	n->_name = Name;
	_nodes[Name] = n;
}
void Graph::AddEdge(string From, string To, int Weight){
	Node *from = _nodes[From];
	Node *to = _nodes[To];
	from->_edges.push_back(make_pair(to, Weight));
}
void Graph::DeleteAllInEdges(string To){
	for (auto n : _nodes){
		DeleteEdge(n.first, To);
	}
}
void Graph::DeleteNode(string Name){
	DeleteAllInEdges(Name);
	delete _nodes[Name];
	_nodes.erase(_nodes.find(Name));
}
void Graph::DeleteEdge(string From, string To){
	Node *ptr = _nodes[From];
	list<pair<Node *, int>>::iterator i = ptr->_edges.begin();
	while (i != ptr->_edges.end()){
		if (i->first->_name == To){
			i = ptr->_edges.erase(i);
			return;
		}
		else{
			i++;
		}
	}
}
int Graph::InDegree(string Name){
	int _degree = 0;
	for (auto n : _nodes){
		for (auto e : n.second->_edges){
			if (e.first->_name == Name){
				_degree++;
			}
		}
	}
	return _degree;
}

void Graph::PageRank(float d)
{
	map<string, float> _ranks;
	map<string, int> _cardinalities;
	for (auto n : _nodes)
	{
		_ranks[n.first] = 1.0 / _nodes.size();
		_cardinalities[n.first] = n.second->_edges.size();
	}
	for (int i = 0; i < 10; i++)
	{
		map<string, float> _new_ranks;
		for (auto n : _nodes)
		{
			for (auto e : n.second->_edges)
			{
				string from = n.first;
				string to = e.first->_name;
				if (_new_ranks.find(to) != _new_ranks.end())
				{
					_new_ranks[to] = (1 - d) / _nodes.size() + _ranks[from] / _cardinalities[from];
				}
				else
				{
					_new_ranks[to] += _ranks[from] / _cardinalities[from];
				}
			}
		}
		for (auto s : _new_ranks)
		{
			_ranks[s.first] = _new_ranks[s.first] * d;
			cout << s.first << ":" << _ranks[s.first] << "\t";
		}
		cout << endl;
	}
}

void Graph::PrintSortOrder()
{
	Graph g(*this);
	queue<string> _node_to_delete;
	while (!g._nodes.empty())
	{
		for (auto n : g._nodes)
		{
			if (g.InDegree(n.first) == 0)
			{
				_node_to_delete.push(n.first);
				cout << n.first << "\t";
			}
		}
		while (!_node_to_delete.empty())
		{
			g.DeleteNode(_node_to_delete.front());
			_node_to_delete.pop();
		}
		cout << endl;
	}
}

void main(){
	Graph g;
	g.AddNode("A");
	g.AddNode("B");
	g.AddNode("C");
	g.AddNode("D");
	g.AddNode("E");
	g.AddEdge("B", "A", 2);
	g.AddEdge("C", "A", 4);
	g.AddEdge("C", "E", 1);
	g.AddEdge("D", "A", 7);
	g.AddEdge("D", "E", 10);
	g.PrintSortOrder();
}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node
{
public:
	Node(int value);
	void link(Node* node);
	vector<Node*> linked;
	int value;
	bool visited;
};

Node::Node(int value) : value(value), visited(false)
{
};

void Node::link(Node* node)
{
	linked.push_back(node);
}

Node* createGraph();

void main()
{
	Node* graph = createGraph();
	queue<Node*> q;
	bool visited[10];

	q.push(graph);
	graph->visited = true;
	cout << graph->value << endl;

	while (!q.empty())
	{
		for (auto l : q.front()->linked)
		{
			if (!l->visited)
			{
				l->visited = true;
				q.push(l);
				cout << l->value << endl;
			}
		}
		q.pop();
	}
}

Node* createGraph()
{
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	Node* n6 = new Node(6);
	Node* n7 = new Node(7);

	n1->link(n2);
	n1->link(n4);
	n2->link(n3);
	n2->link(n5);
	n2->link(n6);
	n4->link(n3);
	n4->link(n5);
	n4->link(n6);
	n3->link(n6);
	n5->link(n6);
	n6->link(n7);

	return n1;
}
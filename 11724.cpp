#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> *node;
int n, m;

int main()
{
	int c = 0;
	queue<int> q;
	queue<int> start;
	bool* visited;

	cin >> n >> m;
	node = new vector<int>[n + 1];
	visited = new bool[n + 1];
	for (int i = 1; i < n + 1; i++)
	{
		visited[i] = false;
		start.push(i);
	}

	int n1, n2;
	for (int i = 0; i < m; i++)
	{
		cin >> n1 >> n2;

		node[n1].push_back(n2);
		node[n2].push_back(n1);
	}

	while (!start.empty())
	{
		q.push(start.front());
		visited[start.front()] = true;

		while (!q.empty())
		{
			for (int l : node[q.front()])
			{
				if (!visited[l])
				{
					visited[l] = true;
					q.push(l);
				}
			}

			q.pop();
		}

		start.pop();
		while (!start.empty() && visited[start.front()])
		{
			start.pop();
		}
		c++;
	}

	cout << c << endl;
	delete[] node;
	delete[] visited;
}
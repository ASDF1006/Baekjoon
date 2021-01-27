#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int cur);
void bfs(int start);

vector<int> graph[1001];
queue<int> q;

int n, m, v;
bool visited1[1001];
bool visited2[1001];

int main()
{
	cin >> n >> m >> v;

	int n1, n2;
	for (int i = 0; i < m; i++)
	{
		cin >> n1 >> n2;

		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}

	for (int i = 0; i < n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << endl;
	bfs(v);
	cout << endl;
}

void dfs(int cur)
{
	cout << cur << ' ';
	visited1[cur] = true;

	for (int i : graph[cur])
	{
		if (!visited1[i])
		{
			dfs(i);
		}
	}
}

void bfs(int start)
{
	q.push(start);
	visited2[start] = true;

	while (!q.empty())
	{
		cout << q.front() << ' ';
		for (int i : graph[q.front()])
		{
			if (!visited2[i])
			{
				visited2[i] = true;
				q.push(i);
			}
		}
		q.pop();
	}
}
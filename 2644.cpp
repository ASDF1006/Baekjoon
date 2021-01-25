#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> node[101];
queue<int> q;
int c[101];
int n, m, u, v;

int main()
{
	cin >> n;
	cin >> u >> v;
	cin >> m;

	int cnt = 0;
	int n1, n2;
	for (int i = 0; i < m; i++)
	{
		cin >> n1 >> n2;
		node[n1].push_back(n2);
		node[n2].push_back(n1);
	}

	q.push(u);
	c[u] = 1;

	while (!q.empty())
	{
		for (int i : node[q.front()])
		{
			if (!c[i])
			{
				q.push(i);
				c[i] = c[q.front()] + 1;
			}
		}
		q.pop();
	}

	cout << c[v] - 1 << endl;
}
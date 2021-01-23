#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int cnt = 0;
vector<int>* node;
queue<int> q;
int visited[101];

int main()
{
	cin >> n;
	cin >> m;
	
	node = new vector<int>[n + 1];

	int n1, n2;
	for (int i = 0; i < m; i++)
	{
		cin >> n1 >> n2;
		node[n1].push_back(n2);
		node[n2].push_back(n1);
	}

	q.push(1);
	visited[1] = true;

	while (!q.empty())
	{
		for (int l : node[q.front()])
		{
			if (!visited[l])
			{
				cnt++;
				visited[l] = true;
				q.push(l);
			}
		}
		q.pop();
	}

	cout << cnt << endl;
	delete[] node;
}
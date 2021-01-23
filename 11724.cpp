#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> node[1001];
queue<int> q;
bool visited[1001];
int n, m;

int main()
{
	int c = 0;

	cin >> n >> m;

	int n1, n2;
	for (int i = 0; i < m; i++)
	{
		cin >> n1 >> n2;

		node[n1].push_back(n2);
		node[n2].push_back(n1);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			c++;
			q.push(i);
			visited[i] = true;

			while (!q.empty())
			{
				for (int l : node[q.front()])
				{
					if (!visited[l])
					{
						q.push(l);
						visited[l] = true;
					}
				}
				q.pop();
			}
		}
	}

	cout << c << endl;
}
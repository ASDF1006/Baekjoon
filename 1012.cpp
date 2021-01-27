#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int t, w, h, n;
vector<int> answer;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main()
{
	cin >> t;

	while (t--)
	{
		bool visited[50][50] = { 0 };
		bool farm[50][50] = { 0 };

		cin >> w >> h >> n;

		int x, y;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;

			farm[y][x] = true;
		}

		for(int i = 0;i<h;i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (visited[i][j] || !farm[i][j]) continue;

				visited[i][j] = true;
				queue<pair<int, int>> q;
				q.push({ j, i });
				while (!q.empty())
				{
					for (int k = 0; k < 4; k++)
					{
						int nx = q.front().first + dx[k];
						int ny = q.front().second + dy[k];
						if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;

						if (!visited[ny][nx] && farm[ny][nx])
						{
							q.push({ nx, ny });
							visited[ny][nx] = true;
						}
					}
					q.pop();
				}
				cnt++;
			}
		}
		answer.push_back(cnt);
	}
	for (int a : answer)
	{
		cout << a << endl;
	}
}
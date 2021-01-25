#include <iostream>
#include <queue>

using namespace std;

struct Pos
{
	Pos(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int x, y;
};

int n, m;
int maze[100][100];
int visited[100][100];
queue<Pos> q;

int main()
{
	cin >> n >> m;
	string s;

	for (int i = 0; i < n; i++)
	{
		cin >> s; 

		for (int j = 0; j < m; j++)
		{
			maze[i][j] = s[j] - '0';
		}
	}

	q.push(Pos(0, 0));
	visited[0][0] = 1;

	while (!q.empty())
	{
		Pos cur = q.front();

		if (cur.x > 0
			&& maze[cur.y][cur.x - 1]
			&& !visited[cur.y][cur.x - 1])
		{
			q.push(Pos(cur.x - 1, cur.y));
			visited[cur.y][cur.x - 1] = visited[cur.y][cur.x] + 1;
		}
		if (cur.x < m - 1
			&& maze[cur.y][cur.x + 1]
			&& !visited[cur.y][cur.x + 1])
		{
			q.push(Pos(cur.x + 1, cur.y));
			visited[cur.y][cur.x + 1] = visited[cur.y][cur.x] + 1;
		}
		if (cur.y > 0
			&& maze[cur.y - 1][cur.x]
			&& !visited[cur.y - 1][cur.x])
		{
			q.push(Pos(cur.x, cur.y - 1));
			visited[cur.y - 1][cur.x] = visited[cur.y][cur.x] + 1;
		}
		if (cur.y < n - 1
			&& maze[cur.y + 1][cur.x]
			&& !visited[cur.y + 1][cur.x])
		{
			q.push(Pos(cur.x, cur.y + 1));
			visited[cur.y + 1][cur.x] = visited[cur.y][cur.x] + 1;
		}
		q.pop();
	}

	cout << visited[n - 1][m - 1] << endl;
}
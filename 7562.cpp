#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Pos
{
	Pos() : x(0), y(0) {}
	Pos(int x, int y) : x(x), y(y) {}

	bool operator== (const Pos& rhs) const
	{
		return (x == rhs.x && y == rhs.y);
	}

	int x, y;
};

queue<int> answer;
int n, l;
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main()
{
	cin >> n;

	Pos start, end;
	int* visited;

	for (int i = 0; i < n; i++)
	{
		queue<Pos> q;

		cin >> l;
		cin >> start.x >> start.y;
		cin >> end.x >> end.y;

		visited = new int[l * l];
		memset(visited, 0, l * l  * 4);

		q.push(start);
		visited[start.y * l + start.x] = 1;

		while (!q.empty())
		{
			if (start == end) break;

			Pos cur = q.front();
			Pos next;

			for (int i = 0; i < 8; i++)
			{
				next = Pos(cur.x + dx[i], cur.y + dy[i]);

				if (0 <= next.x && next.x < l
					&& 0 <= next.y && next.y < l
					&& !visited[next.y * l + next.x])
				{
					visited[next.y * l + next.x] = visited[cur.y * l + cur.x] + 1;
					q.push(next);
					if (next == end) break;
				}
			}
			if (next == end) break;
			q.pop();
		}

		answer.push(visited[end.y * l + end.x] - 1);
		delete[] visited;
	}

	while (!answer.empty())
	{
		cout << answer.front() << endl;
		answer.pop();
	}
}
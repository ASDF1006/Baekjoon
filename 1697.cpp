#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> q;
int visited[100001];

int main()
{
	cin >> n >> k;

	q.push(n);
	visited[n] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		if (cur > 0 && !visited[cur - 1])
		{
			visited[cur - 1] = visited[cur] + 1;
			q.push(cur - 1);
			if (cur - 1 == k) break;
		}
		if (cur < 100001 && !visited[cur + 1])
		{
			visited[cur + 1] = visited[cur] + 1;
			q.push(cur + 1);
			if (cur + 1 == k) break;
		}
		if (cur * 2 < 100001 && !visited[cur * 2])
		{
			visited[cur * 2] = visited[cur] + 1;
			q.push(cur * 2);
			if (cur * 2 == k) break;
		}
		q.pop();
	}

	cout << visited[k] - 1 << endl;
}
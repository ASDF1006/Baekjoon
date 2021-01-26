#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void clear();

int n, w, h;
int answer[100];

int visited[1000][1000];
char b[1000][1000];

int start;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int minEscape;
bool findFire;
bool findEscape;
bool firstEscape;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> w >> h;

		for (int j = 0; j < h; j++)
		{
			cin >> b[j];
		}

		firstEscape = true;
		for (int j = 0; j < h; j++)
		{
			for (int k = 0; k < w; k++)
			{
				if (j != 0 && j != h - 1 && k != 0 && k != w - 1) continue;

				if (b[j][k] == '@')
				{
					firstEscape = false;
					minEscape = 1;
				}
				else if (b[j][k] == '.')
				{
					queue<int> q;

					clear();
					q.push(j * w + k);
					visited[j][k] = 1;
					//cout << "find(" << k << ", " << j << "): " << endl;

					findFire = false;
					findEscape = false;
					int escape = 0;
					while (!q.empty())
					{
						int x = q.front() % w;
						int y = q.front() / w;

						for (int l = 0; l < 4; l++)
						{
							int nx = x + dx[l];
							int ny = y + dy[l];
							if (0 <= nx && nx < w && 0 <= ny && ny < h && !visited[ny][nx])
							{
								if (findEscape && escape < visited[y][x] + 1)
								{
									findFire = true;
									break;
								}
								if (b[ny][nx] == '*')
								{
									findFire = true;
									if (findEscape && escape < visited[y][x] + 1) break;
									findEscape = false;
									break;
								}
								else if (b[ny][nx] == '@')
								{
									findEscape = true;
									escape = visited[y][x] + 1;
									//cout << "human in (" << nx << ", " << ny << "), d: " << escape << endl;
								}
								else if (b[ny][nx] == '#')
								{
									visited[ny][nx] = -1;
								}
								else
								{
									visited[ny][nx] = visited[y][x] + 1;
									q.push(ny * w + nx);
								}
							}
						}
						if (findFire) break;
						q.pop();
					}

					if (findEscape)
					{
						if (firstEscape)
						{
							minEscape = escape;
							firstEscape = false;
						}
						else
						{
							minEscape = (minEscape < escape) ? minEscape : escape;
						}
					}
				}

			}
		}
		answer[i] = (!firstEscape) ? minEscape : 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (answer[i] <= 0)
		{
			cout << "IMPOSSIBLE" << endl;
		}
		else
		{
			cout << answer[i] << endl;
		}
	}
}

void clear()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			visited[i][j] = 0;
		}
	}
}
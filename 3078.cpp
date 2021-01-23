#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
unsigned long long cnt = 0;
int name[21];
queue<int> q[21];


int main()
{
	cin >> n >> k;

	string s;
	int l;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		l = s.length();
		q[l].push(i);

		while (q[l].front() < i - k)
		{
			name[l]--;
			q[l].pop();
		}
		//cout << "q[" << l << "].front(): " << q[l].front() << endl;

		cnt += name[l]++;

		//cout << "cnt: " << cnt << endl;
	}

	cout << cnt;
}
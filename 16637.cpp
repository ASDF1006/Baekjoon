#include <iostream>
#include <vector>

using namespace std;

void s(int result, int cur, int pCnt);
int getResult(int n1, int cur, int n2);

int n = 0;
string expr;
int maxNum = INT32_MIN;
vector<int> num;
vector<char> op;

int main()
{
	cin >> n;
	cin >> expr;

	int pCnt = (expr.length() + 1) / 4;

	for (int i = 0; i < expr.length(); i++)
	{
		if (i % 2 == 0)
		{
			num.push_back(expr[i] - '0');
		}
		else
		{
			op.push_back(expr[i]);
		}
	}

	s(num[0], 1, pCnt);

	cout << maxNum << endl;
}

void s(int result, int cur, int pCnt)
{
	for (; cur <= op.size(); cur++)
	{
		if (pCnt > 0 && cur < op.size())
		{
			int tmp = getResult(num[cur], cur, num[cur + 1]);
			int r = getResult(result, cur - 1, tmp);

			//cout << cur << ": ";
			//cout << r;
			//for (int i = cur + 1; i < op.size(); i++)
			//{
			//	cout << op[i] << num[i + 1];
			//}
			//cout << endl;

			if (cur + 2 < op.size())
			{
				s(r, cur + 2, pCnt - 1);
			}
			else
			{
				s(r, cur + 2, 0);
			}
		}

		result = getResult(result, cur - 1, num[cur]);
	}

//	cout << result << endl;
	maxNum = (maxNum > result) ? maxNum : result;
}

int getResult(int n1, int cur, int n2)
{
	switch (op[cur])
	{
	case '+': n1 += n2; break;
	case '-': n1 -= n2; break;
	case '*': n1 *= n2; break;
	}
	return n1;
}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//int n;
//string str;
//int ans = -987654321;
//
//int cal(int a, int b, char oper) {
//	int result = a;
//
//	switch (oper) {
//	case '+':
//		result += b;
//		break;
//	case '-':
//		result -= b;
//		break;
//	case '*':
//		result *= b;
//		break;
//	}
//	return result;
//}
//
//void dfs(int idx, int sum) {
//	if (idx > n - 1) {
//		ans = max(ans, sum);
//		return;
//	}
//
//	if (idx == 0) {
//		dfs(2, str[idx] - '0');
//		return;
//	}
//
//	if (idx + 2 < n) {
//		int now = cal(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
//		dfs(idx + 4, cal(sum, now, str[idx - 1]));
//	}
//	dfs(idx + 2, cal(sum, str[idx] - '0', str[idx - 1]));
//}
//
//int main() {
//	cin >> n;
//	cin >> str;
//
//	dfs(0, 0);
//
//	cout << ans << endl;
//}
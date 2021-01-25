#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void p(stack<char> &op, int opCnt = 100);
void postfix(string expr, int& cur);

queue<char> ch;

int main()
{
	string expr;

	cin >> expr;
	
	int cur = 0;

	postfix(expr, cur);
}

void postfix(string expr, int& cur)
{
	stack<char> op;

	bool m = false;
	for (; cur < expr.length(); cur++)
	{
		char c = expr[cur];

		if (c == '(')
		{
			postfix(expr, ++cur);
			if (m)
			{
				p(op, 1);
				m = false;
			}
		}
		else if (c == ')')
		{
			break;
		}
		else if ('A' <= c && c <= 'Z')
		{
			ch.push(c);
			if (m)
			{
				p(op, 1);
				m = false;
			}
		}
		else if (c == '*' || c == '/')
		{
			op.push(c);
			m = true;
		}
		else if (c == '+' || c == '-')
		{
			p(op);
			op.push(c);
		}
	}

	p(op);
}

void p(stack<char> &op, int opCnt)
{
	while (!ch.empty())
	{
		cout << ch.front();
		ch.pop();
	}
	for (int i = 0; i < opCnt; i++)
	{
		if (op.empty()) break;
		cout << op.top();
		op.pop();
	}
}
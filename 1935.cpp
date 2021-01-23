#include <iostream>
#include <map>
#include <stack>

using namespace std;

int n;
string input;
map<char, int> num;
stack<double> s;

int main()
{
	cin >> n;
	cin >> input;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i + 'A'];
	}

	for (char c : input)
	{
		if ('A' <= c && c <= 'Z')
		{
			s.push(num[c]);
		}
		else
		{
			double tmp = s.top();
			s.pop();

			switch (c)
			{
			case '+': s.top() += tmp; break;
			case '-': s.top() -= tmp; break;
			case '*': s.top() *= tmp; break;
			case '/': s.top() /= tmp; break;
			}
		}
	}

	printf("%.2f", s.top());
}
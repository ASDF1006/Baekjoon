#include <iostream>
#include <vector>

using namespace std;

void getResult(int result, int j, int numArr[], int operatorArr[]);

int n = 0;
int maxValue = -1000000000;
int minValue = 1000000000;

int main()
{
	cin >> n;

	int* num = new int[n];
	int op[4];

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
	}

	getResult(num[0], 1, num, op);

	cout << maxValue << endl << minValue << endl;
}

void getResult(int result, int count, int num[], int op[])
{
	for (int i = 0; i < 4; i++)
	{
		if (op[i] <= 0)
		{
			continue;
		}

		int tmp;

		switch (i)
		{
		case 0: tmp = result + num[count]; break;
		case 1: tmp = result - num[count]; break;
		case 2: tmp = result * num[count]; break;
		case 3: tmp = result / num[count]; break;
		}

		if (count == n - 1)
		{
			maxValue = (maxValue > tmp) ? maxValue : tmp;
			minValue = (minValue < tmp) ? minValue : tmp;
			return;
		}

		op[i]--;
		getResult(tmp, count + 1, num, op);
		op[i]++;
	}
}
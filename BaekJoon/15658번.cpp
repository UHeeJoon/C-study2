#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int calculate(const int current_num, const int next_num, const int op)
{
	int result = 0;
	switch (op)
	{
	case 0: result = current_num + next_num; break;
	case 1: result = current_num - next_num; break;
	case 2: result = current_num * next_num; break;
	case 3: result = current_num / next_num; break;
	default:break;
	}
	return result;
}
void backtracking(vector<int>& num, vector<int>& op, const int n, const int value, const int idx, int& max, int& min)
{
	if (idx == n)
	{
		max = max < value ? value : max;
		min = min > value ? value : min;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		op[i]--;
		if (op[i] > -1)
		{
			backtracking(num, op, n, calculate(value, num[idx], i), idx + 1, max, min);
		}
		op[i]++;
	}
}
int main()
{
	FAST_IO;
	int n; cin >> n;
	vector<int> num(n);
	vector<int> op(4, 0);
	for (int& el : num)
	{
		cin >> el;
	}
	for (int& el : op)
	{
		cin >> el;
	}
	int min = INT32_MAX, max = INT32_MIN;
	backtracking(num, op, n, num[0], 1, max, min);
	cout << max << ' ' << min << '\n';
	return 0;
}
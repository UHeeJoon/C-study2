#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
void backtracking(const int n, int& k, const int value, const string& exp)
{
	if (k == 0)
	{
		for_each(exp.begin() + 1, exp.end(), [](const char& c)->void { cout << c; });
		cout << '\n';
		return;
	}
	for (int i = 1; i < 4; i++)
	{
		if (value + i > n || k == 0)
		{
			continue;
		}
		if (value + i == n)
		{
			k--;
		}
		backtracking(n, k, value + i, exp + "+" + to_string(i));
	}
}
int main()
{
	FAST_IO;
	int n, k; cin >> n >> k;
	bool flag = false;
	backtracking(n, k, 0, "");
	if (k)
	{
		cout << -1 << '\n';
	}
	return 0;
}
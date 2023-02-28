// https://www.acmicpc.net/problem/3985
// 롤 케이크

#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int l, n;
	cin >> l >> n;
	vector<int>roll_cake(l + 1);
	int expectation_a = 0;
	int expectation = 0;
	int real_a = 0;
	int real = 0;
	for (int i = 1; i <= n; i++)
	{
		int count = 0;
		int p, k; cin >> p >> k;
		if (expectation < k - p + 1)
		{
			expectation = k - p + 1;
			expectation_a = i;
		}
		for (; p <= k; p++)
		{
			if (!roll_cake[p])
			{
				roll_cake[p] = i;
				count++;
			}
		}
		if (real < count)
		{
			real_a = i;
			real = count;
		}
	}
	cout << expectation_a << '\n' << real_a << '\n';
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	int n, m; cin >> n >> m;
	int answer = 0;
	vector<bool> num(n + 1);
	while (m--)
	{
		int tmp; cin >> tmp;
		for (int i = tmp; i <= n; i += tmp)
		{
			num[i] = true;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (num[i])
		{
			answer += i;
		}
	}
	cout << answer << '\n';
	return 0;
}
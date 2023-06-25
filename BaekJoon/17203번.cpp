#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	int n, q; cin >> n >> q;
	int current = 0;
	vector<int> tempo(n + 2);
	for (int i = 1; i <= n; i++)
	{
		int num; cin >> num;
		tempo[i] = tempo[i - 1] + abs(num - current);
		current = num;
	}
	while (q--)
	{
		int start, end;
		cin >> start >> end;
		if (start == end)
		{
			cout << 0 << '\n';
			continue;
		}
		cout << tempo[end] - tempo[start] << '\n';
	}
	return 0;
}
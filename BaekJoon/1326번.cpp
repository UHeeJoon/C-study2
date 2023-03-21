#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	int n; cin >> n;
	vector<int> stepping_stone(n + 1);
	vector<bool>visited(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> stepping_stone[i];
	}
	int a, b; cin >> a >> b;
	int ans = -1;
	queue<pair<int, int>> q;
	q.emplace(a, 0);
	visited[a] = true;
	while (!q.empty())
	{
		const pair<int, int> cur = q.front();
		q.pop();
		if (cur.first == b)
		{
			ans = cur.second;
			break;
		}
		for (int i = 1; cur.first + stepping_stone[cur.first] * i <= n; i++)
		{
			const int next = cur.first + stepping_stone[cur.first] * i;
			if (visited[next]) continue;
			visited[next] = true;
			q.emplace(next, cur.second + 1);
		}
		for (int i = 1; cur.first - stepping_stone[cur.first] * i >= 1; i++)
		{
			const int next = cur.first - stepping_stone[cur.first] * i;
			if (visited[next]) continue;
			visited[next] = true;
			q.emplace(next, cur.second + 1);
		}
	}
	cout << ans << '\n';
	return 0;
}
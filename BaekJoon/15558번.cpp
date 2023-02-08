#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main()
{
	FAST_IO;
	int n, k; cin >> n >> k;
	vector<vector<bool>> v(2, vector<bool>(n));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c; cin >> c;
			v[i][j] = c - '0';
		}
	}
	queue<pair<pair<int, int>, int>>q;
	q.push({ {0,0}, 0 });
	bool flag = false;
	while (!q.empty())
	{
		const pair<pair<int, int>, int> p = q.front();
		q.pop();
		for (const pair<int, int> a : { make_pair(0,1), make_pair(0,-1), make_pair(p.first.first ? -1 : 1,k) })
		{
			int y = p.first.first + a.first;
			int x = p.first.second + a.second;
			if (x >= n) {
				flag = true;
				break;
			}
			if (x <= p.second || !v[y][x]) continue;
			q.push({ { y, x }, p.second + 1 });
			v[y][x] = false;
		}
		if (flag)break;
	}
	cout << (flag ? 1 : 0) << '\n';
	return 0;
}
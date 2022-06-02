#include<bits/stdc++.h>
using namespace std;
int board[110];
int n, m;
void bfs() {
	queue<pair<int, int>> q; q.push({ 1, 0 });
	while (!q.empty()) {
		int locate = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int i = 1; i <= 6; i++) {
			if (locate + i > 100 || board[locate + i] == -1) {
				continue;
			}
			if (locate + i == 100) {
				cout << cnt + 1 << '\n';
				return;
			}
			if (board[locate + i] > 0) {
				q.push({ board[locate + i], cnt + 1 });
				board[locate + i] = -1;
			}
			else if (board[locate + i] == 0) {
				q.push({ locate + i, cnt + 1 });
				board[locate + i] = -1;
			}

		}

	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int a, b; cin >> a >> b;
		board[a] = b;
	}
	bfs();
	return 0;
}
/*
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// ladder or snake;
int los[101];
int d[101];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;
		los[n1] = n2;
	}
	for (int i = 0; i < m; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;
		los[n1] = n2;
	}

	queue<int> q;
	memset(d, -1, sizeof(d));
	q.push(1);
	d[1] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; ++i)
		{
			int nx = x + i;
			if (nx > 100) continue;

			// ladder or snake라면 이동해야 한다.
			if (los[nx] != 0) {
				nx = los[nx];
			}
			if (d[nx] == -1) {
				d[nx] = d[x] + 1;
				q.push(nx);
			}
		}
	}
	cout << d[100] << "\n";
	return 0;
}
*/
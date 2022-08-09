#include<bits/stdc++.h>
using namespace std;
int n, m, k;
bool visited[1001][1001][11];
bool way[1001][1001];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {1,1},{0, 1} });
	visited[1][1][0] = 1;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int check = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (y == n && x == m)
			return cnt;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || ny > n || nx < 1 || nx > m)continue;
			if (way[ny][nx]) {
				if (check < k && !visited[ny][nx][check + 1]) {
					visited[ny][nx][check + 1] = 1;
					q.push({ {ny, nx}, {check + 1, cnt + 1} });
				}
			}
			else {
				if (!visited[ny][nx][check]) {
					visited[ny][nx][check] = 1;
					q.push({ {ny, nx},{check, cnt + 1} });
				}
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			way[i][j] = s[j - 1] - '0';
		}
	}
	cout << bfs() << '\n';;
	return 0;
}
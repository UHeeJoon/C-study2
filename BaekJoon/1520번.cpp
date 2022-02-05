#include<iostream>
using namespace std;
int _map[501][501],dp[501][501], m, n, cnt;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
int dfs(int y, int x) {
	if (y == m - 1 && x == n - 1) return 1;
	if (dp[y][x] != -1) return dp[y][x];
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= m || nx < 0 || nx >= n || _map[ny][nx] >= _map[y][x]) continue;
		dp[y][x] += dfs(ny, nx);
	}
	return dp[y][x];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> _map[i][j];
			dp[i][j] = -1;
		}
	}
	cout << dfs(0, 0) << "\n";
}
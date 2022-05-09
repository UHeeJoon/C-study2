#include<bits/stdc++.h>
using namespace std;
#define MAX 52
char board[MAX][MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int n, m;
int dfs(int y, int x) {
	if (y < 1 || x < 1 || y >n || x > m || board[y][x] == 'H') return 0;
	if (visited[y][x]) {
		cout << -1 << '\n';
		exit(0);
	}
	if (dp[y][x] != -1)
		return dp[y][x];
	visited[y][x] = true;
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + ((board[y][x] - '0') * dy[i]);
		int nx = x + ((board[y][x] - '0') * dx[i]);
		dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
	}
	visited[y][x] = false;
	return dp[y][x];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = -1;
			cin >> board[i][j];
		}
	}
	cout << dfs(1, 1) << '\n';
	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 501
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, _max, dp[MAX][MAX], woods[MAX][MAX];
int dfs(int y, int x) {
	if (dp[y][x]) return dp[y][x];
	dp[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (woods[y][x] >= woods[ny][nx])continue;
		dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
	}
	return dp[y][x];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> woods[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			_max = max(_max, dfs(i, j));
	cout << _max << "\n";
	return 0;
}
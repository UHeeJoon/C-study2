#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
int dp[17][17];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, k; cin >> n >> m >> k;
	int y = 1, x = 1;
	if (k != 0) {
		y = k % m == 0 ? k / m : k / m + 1;
		x = k % m == 0 ? m : k % m;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1) dp[i][j] = 1;
			if (j == 1)dp[i][j] = 1;
			if (i == y && j > x)dp[i][j] = 1;
			if (i > y && j == x)dp[i][j] = 1;
		}
	}
	for (int i = 2; i <= y; i++) {
		for (int j = 2; j <= x; j++) {
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
		}
	}

	for (int i = y + 1; i <= n; i++) {
		for (int j = x + 1; j <= m; j++) {
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1];

		}
	}
	cout << dp[y][x] * dp[n][m] << '\n';
	return 0;
}



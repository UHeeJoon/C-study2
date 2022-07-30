#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
int dp[17][17];


int map[16][16];
int d[16][16];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, k; cin >> n >> m >> k;
	int y = 1, x = 1;
	if (k != 0) {
		y = k % m == 0 ? k / m : k / m + 1;
		x = k % m == 0 ? m : k % m;
	}
	for (int i = 0; i <= 16; i++) {
		dp[i][1] = dp[1][i] = 1;
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
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= m; j++)
	//		cout << dp[i][j] << ' ';
	//	cout << '\n';
	//}
	//cout << '\n';
	for (int i = y + 1; i <= n; i++) {
		for (int j = x + 1; j <= m; j++) {
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1];

		}
	}
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= m; j++)
	//		cout << dp[i][j] << ' ';
	//	cout << '\n';
	//}
	//cout << '\n';
	// 
	//if (k == 0)
	//	cout << dp[n][m] << '\n';
	//else
	cout << dp[y][x] * dp[n][m] << '\n';




	//

	//scanf("%d %d %d", &n, &m, &k);
	//d[1][1] = 1;
	//int cnt = 0;
	//int mx, my;

	//if (k == 0) {
	//	mx = 1;
	//	my = 1;
	//}
	//else {
	//	for (int i = 1; i <= n; i++) {
	//		for (int j = 1; j <= m; j++) {
	//			cnt++;
	//			if (cnt == k) {
	//				mx = i;
	//				my = j;
	//				break;
	//			}
	//		}
	//	}
	//}

	//for (int i = 1; i <= mx; i++) {
	//	for (int j = 1; j <= my; j++) {
	//		d[i][j] += d[i - 1][j] + d[i][j - 1];
	//	}
	//}

	//int x2 = d[mx][my];
	//d[mx][my] = 1;

	//for (int i = mx; i <= n; i++) {
	//	for (int j = my; j <= m; j++) {
	//		if (i == mx && j == my) {
	//			continue;
	//		}
	//		d[i][j] += d[i - 1][j] + d[i][j - 1];
	//	}
	//}
	//int y2 = d[n][m];
	//printf("%d\n", x2 * y2);
	return 0;
}



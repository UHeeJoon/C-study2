#include<bits/stdc++.h>
using namespace std;
#define MAX 100010
#define INF 2147483647
int  n, k;
int dp[100][MAX];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int q, w, e, r;
		cin >> q >> w >> e >> r;
		if (i == 0) {
			dp[0][q] = w;
			dp[0][e] = max(dp[0][e], r);
		}
		else {
			for (int j = 0; j <= k; j++) {
				if (!dp[i - 1][j]) continue;
				if (j + q <= k) dp[i][j + q] = max(dp[i][j + q], dp[i - 1][j] + w);
				if (j + e <= k) dp[i][j + e] = max(dp[i][j + e], dp[i - 1][j] + r);
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= k; i++)
		res = max(dp[n - 1][i], res);


	cout << res << '\n';
	return 0;
}
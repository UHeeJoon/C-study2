#include<bits/stdc++.h>
using namespace std;
int dp[10010][4];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T;
	dp[0][1] = dp[1][1] = dp[2][1] = dp[2][2] = 1;
	while (T--) {
		int n; cin >> n;
		if (dp[n][3]) {
			cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
			continue;
		}
		for (int i = 3; i <= n; i++) {
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
			dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
		}
		cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
	}
	return 0;
}
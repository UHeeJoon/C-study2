#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000000
int dp[202][202];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	fill(&dp[1][0], &dp[1][202], 1);
	for (int i = 2; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= j; l++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][l]) % MOD;
			}
		}
	}

	cout << dp[k][n] << '\n';
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000000
int dp[202][202];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	for (int i = 0; i <= (n > k ? n : k); i++) {
		dp[0][i] = dp[i][1] = 1;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 2; j <= k; j++)
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
	}
	cout << dp[n][k] << '\n';
	return 0;
}
*/
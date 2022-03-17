#include<bits/stdc++.h>
#define MOD 15746
using namespace std;
int dp[10000010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = 5;
	for (int i = 5; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	cout << dp[n] << '\n';
	return 0;
}
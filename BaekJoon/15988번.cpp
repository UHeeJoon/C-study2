#include<bits/stdc++.h>
#define MOD 1000000009
using namespace std;
long long dp[1000010], t, n;
long long Plus(long long n) {
	if (dp[n])
		return dp[n];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD + dp[i - 3] % MOD) % MOD;
	}
	return dp[n];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		cout << Plus(n) << '\n';
	}
	return 0;
}
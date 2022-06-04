#include<bits/stdc++.h>
using namespace std;
int dp[1200];
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n; cin >> n;
	fill(dp, dp + 1001, 987654321);
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		for (int j = 1; j <= num; j++) {
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	if (dp[n] == 987654321) cout << -1 << '\n';
	else cout << dp[n] << '\n';
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int dp[10010];
int money[25];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> money[i];
		int m; cin >> m;
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = money[i]; j <= m; j++) {
				dp[j] = dp[j - money[i]] + dp[j];
			}
		}
		cout << dp[m] << '\n';
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}
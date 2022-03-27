#include<bits/stdc++.h>
using namespace std;
int coin[101], dp[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> coin[i];
	fill(dp, dp + 100001, 100001);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++)
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
	}
	cout << (dp[k] == 100001 ? -1 : dp[k]) << '\n';
	return 0;
}
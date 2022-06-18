#include<bits/stdc++.h>
using namespace std;
int n;
int dp[100010];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp[1] = 987654321, dp[2] = 1, dp[3] = 987654321, dp[4] = 2, dp[5] = 1;
	for (int i = 6; i <= n; i++)
		dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);
	if (dp[n] > 100000) cout << -1 << '\n';
	else cout << dp[n] << '\n';
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	fill(dp, dp + 100001, 100001);
	dp[0] = 0;
	for (int i : {2, 5}) {
		for (int j = i; j <= n; j++)
			dp[j] = min(dp[j], dp[j - i] + 1);
	}
	cout << (dp[n] == 100001 ? -1 : dp[n]) << '\n';
	return 0;
}
*/
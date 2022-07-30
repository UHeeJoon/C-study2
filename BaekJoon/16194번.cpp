#include<bits/stdc++.h>
using namespace std;
int dp[1010];
int card[1010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
		dp[i] = card[i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i / 2; j++) {
			dp[i] = min({ dp[j] + dp[i - j], dp[i], });
		}
	}
	cout << dp[n] << '\n';
	return 0;
}

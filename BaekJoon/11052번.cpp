#include<bits/stdc++.h>
using namespace std;
int dp[1001], card[1001], n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> card[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = max(dp[i], dp[i - j] + card[j]);
	cout << dp[n] << '\n';
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n, num[10010],dp[10010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i];

	dp[1] = num[1];
	dp[2] = num[1] + num[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + num[i - 1] + num[i], max(dp[i - 2] + num[i], dp[i - 1]));
	}
	cout << dp[n] << '\n';
	return 0;
}
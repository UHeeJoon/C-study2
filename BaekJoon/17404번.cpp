#include<bits/stdc++.h>
using namespace std;
int dp[1010][3];
int RGB[1010][3];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
	int result = 987654321;
	for (int i = 0; i < 3; i++) {
		memset(dp, 0, sizeof(dp));
		for (int j = 0; j < 3; j++) {
			if (i == j)dp[1][i] = RGB[1][i];
			else dp[1][j] = 987654321;
		}
		for (int j = 2; j <= n; j++) {
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + RGB[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + RGB[j][1];
			dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + RGB[j][2];
		}
		for (int j = 0; j < 3; j++) {
			if (i == j)continue;
			result = min(result, dp[n][j]);
		}
	}
	cout << result << '\n';
	return 0;
}
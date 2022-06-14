//#include<bits/stdc++.h>
//using namespace std;
//#define MOD 1000000007
//int dp[1010][1010];
//int n, m;
//int main() {
//	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	cin >> n >> m;
//	dp[1][1] = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (i + 1 <= n)
//				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
//			if (j + 1 <= m)
//				dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
//			if (i + 1 <= n && j + 1 <= m)
//				dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
//		}
//	}
//	cout << dp[n][m] << '\n';
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
unsigned int dp[1010][1010];
int n, m;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	n -= 1, m -= 1;
	for (int i = 0; i < 1002; i++) {
		dp[0][i] = 1;
		dp[i][0] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
		}
	}
	cout << dp[n][m] << '\n';
	return 0;
}
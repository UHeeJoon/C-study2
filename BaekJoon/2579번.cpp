#include<bits/stdc++.h>
using namespace std;
int n, num[310], dp[301][3];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> num[i];
	dp[1][1] = num[1];
	for (int i = 2; i <= n; i++) {
		dp[i][2] = dp[i - 1][1] + num[i];
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + num[i];;
	}
	cout << max(dp[n][1] , dp[n][2]) << '\n';
	return 0;
}
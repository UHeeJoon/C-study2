#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long dp[40];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp[0] = 1;;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i] += dp[j - 1] * dp[i - j];
	cout << dp[n] << '\n';
	return 0;
}
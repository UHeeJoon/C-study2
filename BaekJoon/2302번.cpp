#include<bits/stdc++.h>
using namespace std;
int n, m;
int arr[50];
int dp[50];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	int res = 1;
	for (int i = 1; i <= m; i++)
		cin >> arr[i];
	for (int i = 1; i <= m; i++)
		res *= dp[arr[i] - arr[i - 1] - 1];
	cout << res * dp[n - arr[m]] << '\n';
	return 0;
}
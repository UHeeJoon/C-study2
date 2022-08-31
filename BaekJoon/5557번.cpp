#include<bits/stdc++.h>
using namespace std;
#define MAX 110
#define INF 2147483647
int arr[MAX];
long long dp[MAX][MAX / 2];
int n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long ans(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int target = arr[n];
	dp[1][arr[1]] = 1;
	for (int i = 2; i <= n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] == 0)continue;
			if (j + arr[i] <= 20)
				dp[i][j + arr[i]] += dp[i - 1][j];
			if (j - arr[i] >= 0)
				dp[i][j - arr[i]] += dp[i - 1][j];

		}
	}
	ans = dp[n - 1][target];
	cout << ans << '\n';
	return 0;
}
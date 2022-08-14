#include<bits/stdc++.h>
using namespace std;
#define MAX 2230
#define INF 987654321
int arr[MAX][MAX];
int dp[MAX][MAX];
int n;
int move() {
	fill(&dp[0][0], &dp[0][0] + MAX * MAX, INF);
	dp[1][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == n && j == n)return dp[n][n];
			if (j == n) {
				dp[i + 1][j] = dp[i][j] + (arr[i + 1][j] - arr[i][j] < 0 ? 0 : arr[i + 1][j] - arr[i][j] + 1);
			}
			else if (i == n) {
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + (arr[i][j + 1] - arr[i][j] < 0 ? 0 : arr[i][j + 1] - arr[i][j] + 1));
			}
			else {
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + (arr[i][j + 1] - arr[i][j] < 0 ? 0 : arr[i][j + 1] - arr[i][j] + 1));
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (arr[i + 1][j] - arr[i][j] < 0 ? 0 : arr[i + 1][j] - arr[i][j] + 1));
			}
		}
	}
	return dp[n][n];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	cout << move() << '\n';
	return 0;
}
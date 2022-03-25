#pragma warning(disable :4996)
#include<iostream>
using namespace std;
int dp[1000000];
int Plus(int n) {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[n];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << Plus(n) << '\n';
	}
	return 0;
}
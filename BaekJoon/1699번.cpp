#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int square_num(int n) {
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++) {
			if (dp[i] > dp[i - j * j] + 1) {
				dp[i] = dp[i - j * j] + 1;
			}
		}
	}
	return dp[n];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	cout << square_num(n) << endl;
	return 0;
}
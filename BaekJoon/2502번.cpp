#include<bits/stdc++.h>
using namespace std;
int dp[35];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int d, k; cin >> d >> k;
	int i = 1, j = 2;
	while (1) {
		dp[1] = i, dp[2] = j;
		for (int l = 3; l <= d; l++) {
			dp[l] = dp[l - 1] + dp[l - 2];
		}
		if (dp[d] == k) break;
		else if (dp[d] < k)j++;
		else { i++; j = i + 1; }
	}
	cout << i << '\n' << j << '\n';
	return 0;
}
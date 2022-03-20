#include<bits/stdc++.h>
using namespace std;
int n, cnt, arr[1010], dp[1010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
			if (cnt < dp[i]) cnt = dp[i];
		}
	}
	cout << cnt << '\n';
	return 0;
}
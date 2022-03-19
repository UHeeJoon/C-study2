#include<bits/stdc++.h>
using namespace std;
int n, sum, arr[1010], dp[1010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
		if (sum < dp[i])
			sum = dp[i];
	}
	cout << sum << '\n';
	return 0;
}
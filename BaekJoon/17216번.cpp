#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1010];
int dp[1010];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	int _max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i])
				dp[i] = max(dp[i], dp[j] + arr[i]);
			_max = max(_max, dp[i]);
		}
	}
	cout << _max << '\n';
	return 0;
}
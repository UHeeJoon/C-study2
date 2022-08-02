#include<bits/stdc++.h>
using namespace std;
double arr[10010], dp[10010];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(3); cout << fixed;
	int n; cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	dp[1] = arr[1];
	double _max = 0.0;
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1] * arr[i], arr[i]);
		_max = max(_max, dp[i]);
	}
	cout << _max << '\n';
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(dp, dp + 100001, 987654321);
	int n, m; cin >> n >> m;
	dp[n] = 0;
	queue<int> q; q.push(n);
	while (!q.empty()) {
		int tmp = q.front();
		if (tmp == m) {
			break;
		}
		q.pop();
		for (int a : {tmp * 2, tmp + 1, tmp - 1}) {
			int _time = 0;
			if (a != tmp * 2) _time = 1;

			if (a < 0 || a > 100001 || dp[a] <= dp[tmp] + _time) continue;
			q.push(a);
			dp[a] = dp[tmp] + _time;
		}
	}
	cout << dp[m] << '\n';
	return 0;
}
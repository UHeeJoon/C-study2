#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v[10010];
int n, m;
int dp[10010];
int dijkstra() {
	fill(&dp[0], &dp[0] + 10001, 987654321);
	dp[0] = 0;
	for (int i = 1; i <= m; i++) {
		if (!v[i].size())
			dp[i] = dp[i - 1] + 1;
		else {
			for (pair<int, int> start_length : v[i]) {
				dp[i] = min(dp[i], min(dp[i - 1] + 1, dp[start_length.first] + start_length.second));
			}
		}
	}
	return dp[m];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int start, end, length; cin >> start >> end >> length;
		v[end].push_back({ start, length });
	}
	cout << dijkstra() << '\n';
	return 0;
}
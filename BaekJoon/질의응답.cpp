#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int dp[105];
vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; 
	cin >> n;
	v.push_back({ 0,0 });
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				if (dp[j] >= dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
		res = max(res, dp[i]);
	}
	cout << n - res << '\n';
	return 0;
}


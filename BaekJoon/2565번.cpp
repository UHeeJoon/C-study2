#include<bits/stdc++.h>
using namespace std;
int dp[105];
pair<int, int> p[105];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i].first >> p[i].second;
	sort(p + 1, p + n + 1);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (p[i].second > p[j].second) {
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
/*
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
*/
#include<bits/stdc++.h>
using namespace std;
pair<int, int> p[1500010];
int dp[1500100];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int _max = 0;
	for (int i = 1; i <= n; i++) {
		int t, pp; cin >> t >> pp;
		p[i] = { t,pp };
	}
	for (int i = 1; i <= n + 1; i++) {
		_max = max(_max, dp[i]);
		if (i + p[i].first > n + 1) continue;
		dp[i + p[i].first] = max(dp[i + p[i].first], _max + p[i].second);
	}
	cout << _max << '\n';
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector<int> dp(n + 1, 0);
  for (int i = 0; i < n; i++) {
	int x, y;
	cin >> x >> y;
	dp[i + 1] = max(dp[i + 1], dp[i]);
	if (i + x <= n) {
	  dp[i + x] = max(dp[i + x], dp[i] + y);
	}
  }
  cout << dp[n] << '\n';
  return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1010
int dp[MAX], _time[MAX], cnt[MAX];
vector<int> vt[MAX];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> _time[i];
		for (int i = 0; i < k; i++) {
			int u, v; cin >> u >> v;
			vt[u].push_back(v);
			cnt[v]++;
		}
		int w; cin >> w;
		queue<int>q;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] == 0) {
				q.push(i);
				dp[i] = _time[i];
			}
		}
		while (!q.empty()) {
			int tmp = q.front();
			q.pop();
			for (int a : vt[tmp]) {
				int next = a;
				cnt[next]--;
				dp[next] = max(dp[next], dp[tmp] + _time[next]);
				if (cnt[next] == 0)
					q.push(next);
			}
		}
		cout << dp[w] << '\n';
		memset(dp, 0, sizeof(dp));
		memset(_time, 0, sizeof(_time));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < MAX; i++)
			vt[i].clear();
	}
	return 0;
}
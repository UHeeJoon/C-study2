#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool visited[1005];
int cnt;
void dfs(int n) {
	visited[n] = true;
	cnt++;
	for (int a : v[n]) {
		if (!visited[a]) {
			dfs(a);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < 1005; i++)
			v[i].clear();
		int n, m; cin >> n >> m;
		cnt = 0;
		while (m--) {
			int a, b; cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(1);
		cout << cnt - 1 << '\n';
	}
	return 0;
}
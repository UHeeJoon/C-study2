#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, r, cnt = 1, order[100002];
vector<int> vct[200001];
bool visited[100010];
void dfs(int y) {
	order[y] = cnt;
	cnt += 1;
	visited[y] = 1;
	for (int a : vct[y]) {
		if (!visited[a]) {
			dfs(a);
		}
	}
}
bool comp(int i, int j) {
	return i> j;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		vct[u].push_back(v);
		vct[v].push_back(u);
	}
	for (int i = 0; i <= n; i++)
		sort(vct[i].begin(), vct[i].end(), comp);
	dfs(r);
	for (int i = 1; i <= n; i++) {
		cout << order[i] << "\n";
	}
	return 0;
}
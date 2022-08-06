#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
vector<int> tree[10010];
void dfs(vector<int>& edge, int node) {
	for (int a : tree[node]) {
		edge.push_back(a);
		dfs(edge, a);
	}
	return;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a, b;
		for (int i = 0; i < n - 1; i++) {
			int s, e; cin >> s >> e;
			tree[e].push_back(s);
		}
		cin >> a >> b;
		vector<int> a1, b1;
		a1.push_back(a);
		b1.push_back(b);
		dfs(a1, a);
		dfs(b1, b);
		int node = 0;
		for (int a2 : a1) {
			bool flag = false;
			for (int b2 : b1) {
				if (a2 == b2) {
					flag = true;
					node = a2;
					break;
				}
			}
			if (flag)break;
		}
		cout << node << '\n';
		for (int i = 0; i < 10010; i++) {
			tree[i].clear();
		}
	}
	return 0;
}

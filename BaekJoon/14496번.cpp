#include<bits/stdc++.h>
using namespace std;
vector<int> v[1010];
bool visited[1010];
int a, b, n, m;
int bfs() {
	queue<pair<int, int>> q;
	q.push({ a, 0 });
	visited[a] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int cost = q.front().second; q.pop();
		for (int tmp : v[cur]) {
			if (tmp == b)return cost + 1;
			if (visited[tmp])continue;
			visited[tmp] = true;
			q.push({ tmp, cost + 1 });
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int c1, c2; cin >> c1 >> c2;
		v[c1].push_back(c2);
		v[c2].push_back(c1);
	}
	if (a == b)
		cout << 0 << '\n';
	else
		cout << bfs() << '\n';
	return 0;
}
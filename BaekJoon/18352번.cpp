#include<bits/stdc++.h>
using namespace std;
vector<int> v[300001];
bool visited[300001];
int n, m, k, x;
void dijkstra(int start) {
	queue<pair<int, int>> q;
	priority_queue<int, vector<int>, greater<>> pq;
	q.push({ start, 0 });
	visited[start] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cnt == k) {
			pq.push(cur);
			continue;
		}
		for (auto next : v[cur]) {
			if (cnt + 1 > k) continue;
			if (visited[next]) continue;
			visited[next] = true;
			q.push({ next, cnt + 1 });
		}
	}
	if (pq.empty()) cout << -1 << '\n';
	else {
		while (!pq.empty()) {
			cout << pq.top() << '\n';
			pq.pop();
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
	}
	dijkstra(x);
	return 0;
}
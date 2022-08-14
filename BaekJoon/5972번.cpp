#include<bits/stdc++.h>
using namespace std;
#define MAX 50010
vector<pair<int, int>> _map[MAX];
int cow[MAX];
int n, m;
int dijkstra(int start) {
	fill(&cow[0], &cow[0] + MAX, 987654321);
	cow[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cnt = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < _map[cur].size(); i++) {
			int next = _map[cur][i].first;
			int ncnt = _map[cur][i].second;
			if (cow[next] > cnt + ncnt) {
				cow[next] = cnt + ncnt;
				pq.push({ -cow[next], next });
			}
		}
	}
	return cow[n];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		_map[a].push_back({ b, c });
		_map[b].push_back({ a, c });
	}
	cout << dijkstra(1) << '\n';
	return 0;
}
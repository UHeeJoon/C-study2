#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
vector<pair<int, int>> v[810];
int dist[810];
int n, e, v1, v2;
void dijkstra(int start) {
	fill(&dist[0], &dist[0] + 810, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;
			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ -dist[next], next });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> e;
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> v1 >> v2;

	int ans = INF;

	dijkstra(1);
	int stov1 = dist[v1];
	int stov2 = dist[v2];

	dijkstra(v1);
	int v1tov2 = dist[v2];
	int v1toN = dist[n];

	dijkstra(v2);
	int v2toN = dist[n];

	ans = min(ans, stov1 + v1tov2 + v2toN);
	ans = min(ans, stov2 + v1tov2 + v1toN);
	if (v1tov2 == INF || ans == INF) cout << -1 << '\n';
	else cout << ans << '\n';
	return 0;
}
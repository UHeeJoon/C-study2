#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
#define INF 2147483647
vector<pair<int, int>> v[MAX];
int n, m, x;
int dijkstra(int start, int end) {
	int dist[MAX];
	fill(&dist[0], &dist[0] + MAX, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (start != x && cur == end) {
			return dist[end] + dijkstra(end, start);
		}
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;
			if (cost + ncost < dist[next]) {
				dist[next] = cost + ncost;
				pq.push({ -dist[next], next });
			}
		}
	}
	return dist[end];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int start, end, _time; cin >> start >> end >> _time;
		v[start].push_back({ end, _time });
	}
	int _max = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x)continue;
		_max = max(dijkstra(i, x), _max);
	}
	cout << _max << '\n';
	return 0;
}
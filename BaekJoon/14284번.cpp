#include<bits/stdc++.h>
using namespace std;
#define MAX 5010
#define INF 987654321
vector<pair<int, int>> graph[MAX];
int n, m;
int dist[MAX];
int dijkstra(int start, int end) {
	fill(&dist[0], &dist[0] + (n + 1), INF);
	dist[start] = 0;
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int ncost = graph[cur][i].second;
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
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e, d; cin >> s >> e >> d;
		graph[s].push_back({ e,d });
		graph[e].push_back({ s,d });
	}
	int s, t; cin >> s >> t;
	cout << dijkstra(s, t) << '\n';
	return 0;
}
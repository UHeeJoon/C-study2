#include<bits/stdc++.h>
using namespace std;
#define MAX 12
#define INF 987654321
vector<pair<int, int>> v[MAX];
int dist[MAX];
bool visited[MAX];
int n, m, s, e, c;

bool dijkstra(int k) {
	fill(&dist[0], &dist[0] + MAX, INF);
	memset(visited, 0, sizeof(visited));
	visited[s] = true; dist[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int cur = pq.top().second; pq.pop();
		visited[cur] = true;
		if (cur == e)return dist[e] <= c;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;
			if (visited[next] || ncost > k)continue;
			if (dist[next] > dist[cur] + ncost) {
				dist[next] = dist[cur] + ncost;
				pq.push({ -dist[next], next });
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> s >> e >> c;
	for (int i = 0; i < m; i++) {
		int start, end, price; cin >> start >> end >> price;
		v[start].push_back({ end, price });
		v[end].push_back({ start, price });
	}
	int left = -1, right = 1001;
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		if (dijkstra(mid))
			right = mid;
		else left = mid;
	}
	cout << (right == 1001 ? -1 : right) << '\n';
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MAX 100010
#define INF 987654321
vector<pair<int, int>> v[MAX];
int dist[MAX];
int n, m, s, e, c;

bool dijkstra(int k) {
	fill(&dist[0], &dist[0] + MAX, INF);
	dist[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int cur = pq.top().second; pq.pop();
		if (cur == e)return dist[e] <= c;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;
			if (ncost > k)continue;
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
	int left = 0, right = 20;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (dijkstra(mid))
			right = mid - 1;
		else left = mid + 1;
	}
	cout << (left == 21 ? -1 : left) << '\n';
	return 0;
}
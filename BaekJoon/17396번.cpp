#include<bits/stdc++.h>
using namespace std;
#define MAX 100010
#define INF 987654321000000
typedef long long ll;
int n, m;
ll _time[MAX];
int sight[MAX];
vector<pair<int, int>> nexus[MAX];
ll dijkstra(int start) {
	fill(&_time[0], &_time[0] + (n + 1), INF);
	_time[0] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		ll cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (_time[cur] < cost)continue;
		for (int i = 0; i < nexus[cur].size(); i++) {
			int next = nexus[cur][i].first;
			int ncost = nexus[cur][i].second;
			if (cost + ncost < _time[next]) {
				_time[next] = cost + ncost;
				pq.push({ -_time[next], next });
			}
		}

	}
	return _time[n] == INF ? -1 : _time[n];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	n -= 1;
	for (int i = 0; i <= n; i++) cin >> sight[i];
	sight[n] = 0;
	for (int i = 0; i < m; i++) {
		int s, e, t; cin >> s >> e >> t;
		if (sight[s] || sight[e])continue;
		nexus[s].push_back({ e, t });
		nexus[e].push_back({ s, t });
	}
	cout << dijkstra(0) << '\n';
	return 0;
}
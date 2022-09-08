#include<bits/stdc++.h>
using namespace std;
#define MAX 10010
#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;
vector<pair<int, int>> v[MAX];
int n, d, c;
int cnt, _max;
int dist[MAX];
void dijkstra(int start) {
	fill(&dist[0], &dist[0] + MAX, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (auto a : v[cur]) {
			int nCost = cost + a.second;
			int next = a.first;
			if (nCost >= dist[next])continue;
			dist[next] = nCost;
			pq.push({ -nCost, next });
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] != INF) {
			_max = max(_max, dist[i]);
			cnt++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while (tc--) {
		cin >> n >> d >> c;
		while (d--) {
			int a, b, s;
			cin >> a >> b >> s;
			v[b].push_back({ a, s });
		}
		dijkstra(c);
		cout << cnt << ' ' << _max << '\n';
		_max = cnt = 0;
		for (int i = 1; i <= n; i++)
			v[i].clear();
	}
	return 0;
}
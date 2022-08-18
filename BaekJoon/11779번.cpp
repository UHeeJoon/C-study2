#include<bits/stdc++.h>
using namespace std;
#define MAX 1000 + 5
vector<pair<int, int>> v[MAX];
vector<int> way;
int dist[MAX];
int route[MAX];
int n, m;
void dijkstra(int start, int end) {
	for (int i = 1; i <= n; i++)
		dist[i] = 2100000000;
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ start, 0 });
	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();
		if (cost > dist[cur]) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;
			if (cost + ncost < dist[next]) {
				dist[next] = cost + ncost;
				pq.push({ next, -dist[next] });
				route[next] = cur;
			}
		}
	}
	cout << dist[end] << '\n';
	int tmp = end;
	while (tmp) {
		way.push_back(tmp);
		if (tmp == start)break;
		tmp = route[tmp];
	}
	cout << way.size() << '\n';
	for (int i = (int)way.size() - 1; i >= 0; i--)
		cout << way[i] << ' ';
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, length; cin >> start >> end >> length;
		v[start].push_back({ end, length });
	}
	int start, end; cin >> start >> end;
	dijkstra(start, end);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MAX 1010
#define INF 987654321
int s, e;
int dist[MAX];
vector<pair<int, int>> _map[MAX];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        _map[a].push_back({ b,c });
    }
    for (int i = 1; i <= n; i++) dist[i] = INF;
    cin >> s >> e;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, s });
    dist[s] = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cost)
            continue;
        for (int i = 0; i < (int)_map[cur].size(); i++) {
            int next = _map[cur][i].first;
            int ncost = _map[cur][i].second;
            if (dist[next] > cost + ncost) {
                dist[next] = cost + ncost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
    cout << dist[e] << '\n';
    return 0;
}
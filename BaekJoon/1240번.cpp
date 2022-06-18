#include<bits/stdc++.h>
using namespace std;
struct Node { int v, cost; };
int n, m, dist[1001];
vector <Node> graph[1001];
int bfs(int start, int end) {
    queue <int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto next : graph[x]) {
            if (dist[next.v] >= 0) continue;
            dist[next.v] = dist[x] + next.cost;
            q.push(next.v);
        }
    }
    return dist[end];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0, u, v, cost; i < n - 1; i++) {
        cin >> u >> v >> cost;
        graph[u].push_back({ v,cost });
        graph[v].push_back({ u,cost });
    }
    while (m--) {
        int start, end;
        cin >> start >> end;
        memset(dist, -1, sizeof(dist));
        cout << bfs(start, end) << '\n';
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
vector<pair<int, long long> > tree[1001];
long long v[1001];
void bfs(int a, int b) {
    priority_queue<pair<long long, int> > pq;
    pq.push({ 0, a });
    v[a] = 0;
    while (!pq.empty()) {
        int now = pq.top().second;
        long long dist = -pq.top().first;
        pq.pop();
        for (int i = 0; i < (int)tree[now].size(); i++) {
            int next = tree[now][i].first;
            int current = tree[now][i].second;
            if (current + dist < v[next]) {
                v[next] = current + dist;
                pq.push({ -v[next], next });
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, a, b, c;
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		cin >>a>>b>>c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a,c });
	}
	for (int i = 0; i < M; i++) {
		cin >>a>>b;
		for (int i = 0; i <= N; i++)
		    v[i] = INF;
		bfs(a, b);
		cout << v[b] <<'\n';
	}
    return 0;
}
*/
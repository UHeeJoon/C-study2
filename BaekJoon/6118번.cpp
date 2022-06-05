#include<bits/stdc++.h>
using namespace std;
#define MAX 20001
int n, m;
vector<int> v[MAX];
int visited[MAX];
void bfs() {
	int cnt = 1, dist = 0, same = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int now = q.front();
		if (visited[now] > dist) dist = visited[now];
		q.pop();
		for (int next : v[now]) {
			if (visited[next] >= 0) continue;
			visited[next] = visited[now] + 1;
			q.push(next);
		}
	}
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		if (dist == visited[i]) {
			same++;
			if (flag) {
				cnt = i;
				flag = false;
			}
		}
	}
	cout << cnt << ' ' << dist << ' ' << same << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int A_i, B_i; cin >> A_i >> B_i;
		v[A_i].push_back(B_i);
		v[B_i].push_back(A_i);
	}
	memset(visited, -1, sizeof(visited));
	visited[1] = 0;
	bfs();
	return 0;
}
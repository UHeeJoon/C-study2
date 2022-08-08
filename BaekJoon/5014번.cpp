#include<bits/stdc++.h>
using namespace std;
bool visited[1000010];
int bfs(int f, int s, int g, int u, int d) {
	queue<pair<int, int>>q;
	q.push({ s, 0 });
	visited[s] = true;
	while (!q.empty()) {
		int Cur = q.front().first;
		int dept = q.front().second;
		if (Cur == g) {
			return dept;
		}
		q.pop();
		for (int value : {u, -d}) {
			int next = Cur + value;
			if (next < 1 || next > f || visited[next])continue;
			q.push({ next, dept + 1 });
			visited[next] = true;

		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int f, s, g, u, d; cin >> f >> s >> g >> u >> d;
	int res = bfs(f, s, g, u, d);
	if (res == -1)
		cout << "use the stairs\n";
	else cout << res << '\n';
	return 0;
}
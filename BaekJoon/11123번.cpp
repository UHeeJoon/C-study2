#include<bits/stdc++.h>
using namespace std;
#define MAX 105
char _map[MAX][MAX];
int n, m;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
void bfs(int a, int b) {
	queue<int> q; q.push(a * 1000 + b);
	while (!q.empty()) {
		int y = q.front() / 1000;
		int x = q.front() % 1000;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || _map[ny][nx] == '.')continue;
			_map[ny][nx] = '.';
			q.push(ny * 1000 + nx);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> _map[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (_map[i][j] == '#') {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		memset(_map, 0, sizeof(_map));
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MAX 260
int _map[MAX][MAX];
int n, m;
int dy[] = { 0,1,0,-1, 1,-1, 1, -1 };
int dx[] = { 1,0,-1,0, 1, -1, -1 ,1 };
void bfs(int a, int b) {
	queue<int> q; q.push(a * 1000 + b);
	while (!q.empty()) {
		int y = q.front() / 1000;
		int x = q.front() % 1000;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || _map[ny][nx] == 0)continue;
			_map[ny][nx] = 0;
			q.push(ny * 1000 + nx);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> _map[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (_map[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}
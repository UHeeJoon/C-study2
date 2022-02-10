#include<iostream>
#include<queue>
using namespace std;
#define MAX 1001
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int m, n, cnt, tomato[MAX][MAX];
queue<pair<int, int>> q;
void check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) {
				cnt = 0;
				return;
			}
			if (cnt < tomato[i][j])
				cnt = tomato[i][j];
		}
	}
}
void bfs() {
	int y, x;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || tomato[ny][nx]!=0 ) continue;
			tomato[ny][nx] = tomato[y][x] + 1;
			q.push({ ny, nx });
		}	
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
				q.push({ i, j });
		}
	}
	bfs();
	check();
	cout << cnt - 1 << "\n";
	return 0;
}
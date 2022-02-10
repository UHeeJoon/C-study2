
// ½ÇÆÐ

#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
#define MAX 1001
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int m, n, cnt, tomato[MAX][MAX];
queue<pair<int, int>> q;
bool visited[MAX][MAX];
void bfs(queue<pair<int,int>> q) {
	int y, x;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		visited[y][x] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx]) continue;
			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
		cnt += 1;
	}
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j])
				q.push({ i, j });
		}
	}
	bfs(q);
	cout << cnt << "\n";
}
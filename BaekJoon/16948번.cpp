#include<bits/stdc++.h>
using namespace std;
#define MAX 205
int board[MAX][MAX];
bool visited[MAX][MAX];
int n;
int dy[] = { -2, -2, 0, 0, 2, 2 };
int dx[] = { -1, 1, -2, 2, -1, 1 };
void bfs(int y, int x, int end_y, int end_x) {
	visited[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y * 1000 + x, 0 });
	bool flag = true;
	while (!q.empty()) {
		int y2 = q.front().first / 1000;
		int x2 = q.front().first % 1000;
		int cnt = q.front().second;
		q.pop();
		if (y2 == end_y && x2 == end_x) {
			cout << cnt << '\n';
			flag = false;
			break;
		}
		for (int i = 0; i < 6; i++) {
			int ny = y2 + dy[i];
			int nx = x2 + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
			q.push({ ny * 1000 + nx, cnt + 1 });
			visited[ny][nx] = true;;
		}
	}
	if (flag) cout << -1 << '\n';
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int r1, c1, r2, c2;
	cin >> n >> r1 >> c1 >> r2 >> c2;
	bfs(r1, c1, r2, c2);
	return 0;
}
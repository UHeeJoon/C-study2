#include<bits/stdc++.h>
using namespace std;
#define MAX 105
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
char miro[MAX][MAX];
int wall[MAX][MAX];
int n, m;
int bfs(int startY, int startX) {
	fill(&wall[0][0], &wall[0][0] + MAX * MAX, 987654321);
	queue<pair<pair<int, int>, int>> q;
	wall[startY][startX] = 0;
	q.push({ { startY, startX }, wall[startY][startX] });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int ncnt = (miro[ny][nx] - '0');
			if (ny < 1 || ny >n || nx <1 || nx > m) continue;
			if (cnt + ncnt < wall[ny][nx]) {
				wall[ny][nx] = cnt + ncnt;
				q.push({ {ny, nx}, wall[ny][nx] });
			}
		}
	}
	return wall[n][m];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> miro[i][j];
		}
	}
	cout << bfs(1, 1) << '\n';
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int n, m;
int _map[MAX][MAX];
int dist[MAX][MAX];
void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || dist[nextY][nextX] != -1)continue;
			q.push({ nextY,nextX });
			dist[nextY][nextX] = dist[curY][curX] + 1;
		}
	}
	return;
}
void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dist, -1, sizeof(dist));
	cin >> n >> m;
	int y = 0, x = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> _map[i][j];
			if (_map[i][j] == 2) {
				y = i;
				x = j;
			}
			else if (_map[i][j] == 0)
				dist[i][j] = 0;
		}
	}
	dist[y][x] = 0;
	bfs(y, x);
	print();
	return 0;
}
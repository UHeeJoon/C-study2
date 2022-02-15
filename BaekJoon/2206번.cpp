// 틀림 : 시간초과

#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, _max = -1 , visited[1001][1001];
char way[1001][1001];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int bfs() {
	queue<int> q; q.push(0);
	visited[0][0] = 1;
	while (!q.empty()) {
		int y = q.front() / 10000;
		int x = q.front() % 10000;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] != 0 || way[ny][nx] == '1') continue;
			if (ny == n - 1 && nx == m - 1) 
				return visited[y][x] + 1;
			visited[ny][nx] = visited[y][x] + 1;
			q.push(ny * 10000 + nx);
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> way[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (way[i][j] == '1') {
				way[i][j] = '0';
				_max = max(bfs(), _max);
				way[i][j] = '1';
				memset(visited, 0, sizeof(visited));
			}
		}
	}
	cout << _max << "\n";	
	return 0;
}
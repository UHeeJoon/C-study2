#include<bits/stdc++.h>
using namespace std;
#define MAX 51
int space[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int n, m;
int bfs(int a, int b) {
	queue<pair<int, int>>q; q.push({ a * 100 + b , 0 });
	memset(visited, 0, sizeof(visited));
	visited[a][b] = true;
	int cnt = 0;
	while (!q.empty()) {
		int y = q.front().first / 100;
		int x = q.front().first % 100;
		cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])continue;
			if (space[ny][nx] == 1)return cnt + 1;
			visited[ny][nx] = true;
			q.push({ ny * 100 + nx, cnt + 1 });
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int _max = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> space[i][j];;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (space[i][j] == 0) {
				_max = max(_max, bfs(i, j));
			}
		}
	}
	cout << _max << '\n';
	return 0;
}
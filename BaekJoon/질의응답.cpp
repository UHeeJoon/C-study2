#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
int n, m, visited[1001][1001][2];
char way[1001][1001];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {1,1},1 });
	visited[1][1][1] = 1;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int check = q.front().second;
		q.pop();
		if (y == n && x == m)
			return visited[y][x][check];
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || ny > n || nx < 1 || nx > m)continue;
			if (way[ny][nx] == '1' && check) {
				q.push({ {ny, nx}, 0 });
				visited[ny][nx][check - 1] = visited[y][x][check] + 1;
			}
			else if (way[ny][nx] == '0' && visited[ny][nx][check] == 0) {
				q.push({ {ny, nx}, check });
				visited[ny][nx][check] = visited[y][x][check] + 1;
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> way[i][j];

	cout << bfs() << '\n';;
	return 0;
}
/*
10 10
0100000000
1011111110
0100010000
0101010110
0101010110
0101010110
0101010110
0101010110
0101010110
0001000100
*/
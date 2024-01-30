#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int main()
{
	FAST_IO;
	char grid[10][11] = { {'\0',}, };
	constexpr int dy[] = { 0,1,0,-1 };
	constexpr int dx[] = { 1,0,-1,0 };
	queue<pair<int, int>> q;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'B') {
				grid[i][j] = 'R';
				q.emplace(i * 10 + j, 0);
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first / 10;
		int y = q.front().first % 10;
		int dist = q.front().second;
		q.pop();
		if (grid[x][y] == 'L') {
			cout << dist - 1 << '\n';
			break;
		}
		grid[x][y] = 'R';
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10 || grid[nx][ny] == 'R') { continue; }
			q.emplace(nx * 10 + ny, dist + 1);
		}
	}
	return 0;
}
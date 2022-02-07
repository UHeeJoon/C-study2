#include<iostream>
#include<cstring>
using namespace std;
#define MAX 101
int n, m, cnt, cheese[MAX][MAX];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
bool visited[MAX][MAX];
bool check() {
	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < m - 1; j++)
			if (cheese[i][j] != 0)
				return false;
	return true;
}
void nexHour() {
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (cheese[i][j] == 2)
				cheese[i][j] = 1;
			else if (cheese[i][j] >= 3)
				cheese[i][j] = 0;

		}
	}
}
void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
		if (cheese[ny][nx] > 0) {
			cheese[ny][nx] += 1;
			continue;
		}
		dfs(ny, nx);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> cheese[i][j];
	while (true) {
		memset(visited, 0, sizeof(visited));
		dfs(0, 0);
		nexHour();
		cnt++;
		if (check())
			break;
	}
	cout << cnt << "\n";
	return 0;
}
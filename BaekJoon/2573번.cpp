#include<iostream>
#include<cstring>
using namespace std;
#define MAX 301
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int year, n, m, iceburg[MAX][MAX];
bool visited[MAX][MAX];
void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 1 || ny >= n - 1 || nx < 1 || nx >= m - 1 || visited[ny][nx] || !iceburg[ny][nx]) continue;
		dfs(ny, nx);
	}
}
void nextYear(int y, int x) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (iceburg[ny][nx] == 0 && !visited[ny][nx])
			ret += 1;
	}
	iceburg[y][x] = iceburg[y][x] - ret < 0 ? 0 : iceburg[y][x] - ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> iceburg[i][j];
	while (1) {
		int cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (iceburg[i][j] > 0) {
					nextYear(i, j);
					visited[i][j] = 1;
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (iceburg[i][j] > 0 && visited[i][j] == 0) {
					dfs(i, j);
					cnt += 1;
				}
			}
		}

		cout << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << iceburg[i][j] << " ";
			}
			cout << "\n";
		}

		year += 1;
		if (cnt >= 2) break;
		else if (cnt == 0) {
			year = 0;
			break;
		}
	}
	cout << year << "\n";
}

/*
		cout << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << iceburg[i][j] << " ";
			}
			cout << "\n";
		}
*/
#include<iostream>
using namespace std;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int n, cnt, cnt2;
char color[101][101];
char color2[101][101];
void dfs(int y, int x) {
	color2[y][x] = 'A';
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || color2[ny][nx] != color[y][x]) continue;
		dfs(ny, nx);
	}
}
void solution(int &count) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (color2[i][j] != 'A') {
				dfs(i, j);
				count++;
			}
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> color[i][j];
			color2[i][j] = color[i][j];
		}
	}
	solution(cnt);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (color[i][j] == 'R') {
				color2[i][j] = 'G';
				color[i][j] = 'G';
			}
			else
				color2[i][j] = color[i][j];
		}
	}
	solution(cnt2);
	cout << cnt << " " << cnt2 << "\n";
	return 0;
}
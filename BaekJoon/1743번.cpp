#include<iostream>
#include<algorithm>
using namespace std;
int n, m, k, cnt, _max, gate[101][101];
int dy[4] = { 0, 1, -1, 0 };
int dx[4] = { -1, 0, 0, 1 };
void dfs(int y, int x, int ret) {
	gate[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny <1 || ny > n || nx <1 || nx >m || !gate[ny][nx])continue;
		cnt += ret;
		dfs(ny, nx, ret);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int y, x; cin >> y >> x;
		gate[y][x] = 1;
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (gate[i][j]) {
				cnt = 1;
				dfs(i, j, 1);
				_max = max(_max, cnt);
			}
		}
	}	
	cout << cnt << "\n";
	return 0;
}
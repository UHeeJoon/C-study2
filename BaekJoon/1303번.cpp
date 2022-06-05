#include<bits/stdc++.h>
using namespace std;
#define MAX 105
bool visited[MAX][MAX];
char war[MAX][MAX];
int n, m;
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
int dfs(int y, int x, char so) {
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (so != war[ny][nx] || ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx])continue;
		visited[ny][nx] = true;
		cnt += dfs(ny, nx, so);
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> war[i][j];
	int W = 0, B = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				if (war[i][j] == 'W') {
					int tmp = dfs(i, j, war[i][j]);
					W += tmp * tmp;
				}
				else {
					int tmp = dfs(i, j, war[i][j]);
					B += tmp * tmp;
				}
			}
		}
	}
	cout << W << ' ' << B << '\n';
	return 0;
}
/*
#include <stdio.h>

char z[102][104]; int n, m;
int dfs(int y, int x, int c) {
	int r = 1, d[][2] = { 0,1, 1,0, 0,-1, -1,0 }, i;
	z[y][x] = 0;
	for (i = 0; i < 4; i++) {
		int ny = y + d[i][0], nx = x + d[i][1];
		if (z[ny][nx] != c) continue;
		r += dfs(ny, nx, c);
	}
	return r;
}
int main(){
	int i, j, r1 = 0, r2 = 0, s;
	scanf("%d%d", &m, &n);
	for (i = 1; i <= n; i++) scanf("%s", z[i] + 1);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (z[i][j] == 'W') { s = dfs(i, j, 'W'); r1 += s * s; }
			else if (z[i][j] == 'B') { s = dfs(i, j, 'B'); r2 += s * s; }
		}
	}
	printf("%d %d\n", r1, r2);
}
*/
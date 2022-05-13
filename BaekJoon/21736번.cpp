#include<bits/stdc++.h>
using namespace std;
#define MAX 610
char campus[MAX][MAX];
//bool visited[MAX][MAX];
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
int n, m;
void dfs(int y, int x, int& cnt) {
	if (y<1 || y>n || x<1 || x>m || campus[y][x] == 'X') return;
	if (campus[y][x] == 'P') cnt++;
	campus[y][x] = 'X';
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		dfs(ny, nx, cnt);
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int y = 0, x = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> campus[i][j];
			if (campus[i][j] == 'I')
				y = i, x = j;
		}
	}
	int cnt = 0;
	dfs(y, x, cnt);
	if (cnt == 0) cout << "TT\n";
	else cout << cnt << '\n';
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define MAX 610
char campus[MAX][MAX];
//bool visited[MAX][MAX];
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
int n, m;
int bfs(int y, int x, int cnt) {
	queue<pair<int, int>>q;
	q.push({ y, x });
	campus[y][x] = 'X';
	while (!q.empty()) {
		int y1 = q.front().first;
		int x1 = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y1 + dy[i];
			int nx = x1 + dx[i];
			if (ny <1 || ny>n || nx<1 || nx>m || campus[ny][nx] == 'X')continue;
			if (campus[ny][nx] == 'P')cnt++;
			campus[ny][nx] = 'X';
			q.push({ ny, nx });
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int y = 0, x = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> campus[i][j];
			if (campus[i][j] == 'I')
				y = i, x = j;
		}
	}
	int cnt = bfs(y, x, 0);
	if (cnt == 0)cout << "TT\n";
	else cout << cnt << '\n';
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 66
int GAME[MAX][MAX];
bool visited[MAX][MAX];
int n;
void dfs(int y, int x) {
	if (y<1 || y>n || x<1 || x>n || visited[y][x])return;
	if (y == n && x == n) {
		cout << "HaruHaru\n";
		exit(0);
	}
	if (!visited[y][x]) {
		visited[y][x] = true;
		dfs(y, x + GAME[y][x]);
		dfs(y + GAME[y][x], x);
		//visited[y][x] = false;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> GAME[i][j];
	dfs(1, 1);
	cout << "Hing\n";
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define MAX 66
int GAME[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = { 0,1 };
int dx[] = { 1,0 };
int n;
bool bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;
	while (!q.empty()) {
		int y1 = q.front().first;
		int x1 = q.front().second;
		if (y1 == n && x1 == n) return true;
		q.pop();
		for (int i = 0; i < 2;i++) {
			int ny = y1 + dy[i] * GAME[y1][x1];
			int nx = x1 + dx[i] * GAME[y1][x1];
			if (ny < 1 || ny >n || nx <1 || nx>n || visited[ny][nx])continue;
			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> GAME[i][j];
	cout << (bfs(1, 1) ? "HaruHaru\n" : "Hing\n");
	return 0;
}
*/
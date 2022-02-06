#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 501
int n, m, cnt, _max, paper[MAX][MAX];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };
queue<int> q;
int bfs(int i, int j) {
	int ret = 1;
	paper[i][j] = 0;
	q.push(i * 1000 + j);
	while (!q.empty()) {
		int y = q.front() / 1000;
		int x = q.front() % 1000;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || !paper[ny][nx])continue;
			q.push(ny * 1000 + nx);
			paper[ny][nx] = 0;
			ret++;
		}
	}
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paper[i][j]) {
				_max = max(_max, bfs(i ,j));
				cnt += 1;
			}
		}
	}
	cout << cnt << "\n" << _max << "\n";
}
/*
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 501
int n, m, cnt, _max, paper[MAX][MAX];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int dfs(int y, int x , int ret) {
	paper[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || !paper[ny][nx])continue;
		ret = dfs(ny, nx, ret + 1);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paper[i][j]) {
				_max = max(_max, dfs(i, j, 1));
				cnt += 1;
			}
		}
	}
	cout << cnt << "\n" << _max << "\n";
	return 0;
}
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int dy[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int dx[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int w, h, cnt, island[51][51];
queue<int> q;
void bfs(int n) {
	q.push(n);
	while (!q.empty()) {
		int y = q.front() / 100;
		int x = q.front() % 100;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= h || nx < 0 || nx >= w || !island[ny][nx]) continue;
			q.push(ny * 100 + nx);
			island[ny][nx] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true) {
		memset(island, 0, sizeof(island));
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> island[i][j];
		cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (island[i][j]) {
					bfs(i*100+j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}

/*
#include<iostream>
#include<cstring>
using namespace std;
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int w, h, cnt, island[51][51];
void dfs(int y, int x) {
	island[y][x] = 0;
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= h || nx < 0 || nx >= w || !island[ny][nx]) continue;
		dfs(ny, nx);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true) {
		memset(island,0, sizeof(island));
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) 
			for (int j = 0; j < w; j++) 
				cin >> island[i][j];
		cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (island[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
*/
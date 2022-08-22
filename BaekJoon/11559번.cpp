#include<bits/stdc++.h>
using namespace std;
#define MAX 8
#define INF 2147483647
int boomCnt = 0, cnt = 1;
char puyoPuyo[MAX + MAX][MAX];
bool visited[MAX + MAX][MAX];
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
void check(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6 || visited[ny][nx] || puyoPuyo[y][x] != puyoPuyo[ny][nx] || puyoPuyo[ny][nx] == '.') continue;
		visited[ny][nx] = true;
		check(ny, nx);
		cnt++;
	}
	return;
}
void boom(int y, int x, char shape) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		puyoPuyo[y][x] = '.';
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6 || puyoPuyo[ny][nx] != shape) continue;
			q.push({ ny, nx });
		}
	}
	return;
}
bool isBoom() {
	memset(visited, 0, sizeof(visited));
	bool flag = false;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (puyoPuyo[i][j] != '.' && !visited[i][j]) {
				check(i, j);
				if (cnt >= 4) {
					boom(i, j, puyoPuyo[i][j]);
					flag = true;
				}
				cnt = 1;
			}
		}
	}
	return flag;
}
void gravity() {
	for (int i = 0; i < 6; i++) {
		int idx = 11;
		while (idx--) {
			if (puyoPuyo[idx][i] != '.') {
				int tmp = idx + 1;
				if (puyoPuyo[tmp][i] == '.') {
					while (tmp <= 11 && puyoPuyo[tmp][i] == '.') {
						tmp++;
					}
					puyoPuyo[tmp - 1][i] = puyoPuyo[idx][i];
					puyoPuyo[idx][i] = '.';
				}
			}
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> puyoPuyo[i][j];
		}
	}
	int a = 6;
	while (isBoom()) {
		gravity();
		boomCnt++;
		//for (int i = 0; i < 12; i++) {
		//	for (int j = 0; j < 6; j++) {
		//		cout << puyoPuyo[i][j];
		//	}
		//	cout << '\n';
		//}
		//cout << '\n';
	}
	cout << boomCnt << '\n';
	return 0;
}
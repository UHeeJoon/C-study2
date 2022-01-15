#include<iostream>
#include<queue>
#define rep(i,x,n) for(int i=x; i<=n; i++)
using namespace std;
const int INF = 987654321;
char _map[1004][1004];
int n, m, sx, sy, dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 }, ret;
int fire_check[1004][1004], person_check[1004][1004];
bool in(int a, int b) {
	return 1 <= a && a <= n && 1 <= b && b <= m;
}
int main() {
	cin.tie(0), cout.tie(0);
	queue<pair<int, int>> q;
	cin >> n >> m;
	fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);
	rep(i, 1, n) rep(j, 1, m) {
		cin >> _map[i][j];
		if (_map[i][j] == 'F') {
			fire_check[i][j] = 1;
			q.push({ i,j });
		}
		if (_map[i][j] == 'J') {
			sy = i;
			sx = j;
		}
	}
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!in(ny, nx)) continue;
			if (fire_check[ny][nx] != INF || _map[ny][nx] == '#') continue;
			fire_check[ny][nx] = fire_check[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	person_check[sy][sx] = 1;
	q.push({ sy,sx });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (x == m || y == n || x == 1 || y == 1) {
			ret = person_check[y][x];
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!in(ny, nx)) continue;
			if (person_check[ny][nx] || _map[ny][nx] == '#') continue;
			if (fire_check[ny][nx] <= person_check[y][x] + 1) continue;
			person_check[ny][nx] = person_check[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	if (ret != 0) cout << ret << "\n";
	else cout << "IMPOSSIBLE \n";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MAX 1010
//#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;
char fire[MAX][MAX];
int w, h;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int bfs(queue<pair<pair<int, int>, int>> sang, queue<pair<int, int>> fireLocate) {
	int y, x, cnt;
	while (!sang.empty()) {
		int fire_size = fireLocate.size();
		while (fire_size--) {
			y = fireLocate.front().first;
			x = fireLocate.front().second;
			fireLocate.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= h || nx < 0 || nx >= w || fire[ny][nx] == '#' || fire[ny][nx] == '*')continue;
				fireLocate.push({ ny, nx });
				fire[ny][nx] = '*';
			}
		}
		int sang_size = sang.size();
		while (sang_size--) {
			y = sang.front().first.first;
			x = sang.front().first.second;
			cnt = sang.front().second;
			sang.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= h || nx < 0 || nx >= w)return cnt + 1;
				if (fire[ny][nx] == '#' || fire[ny][nx] == '*' || fire[ny][nx] == '@') continue;
				sang.push({ {ny, nx}, cnt + 1 });
				fire[ny][nx] = '@';
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while (tc--) {
		cin >> w >> h;
		queue<pair<int, int>> fireLocate;
		queue<pair<pair<int, int>, int>> sang;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> fire[i][j];
				if (fire[i][j] == '@') {
					sang.push({ {i, j}, 0 });
				}
				else if (fire[i][j] == '*') {
					fireLocate.push({ i, j });
				}
			}
		}
		int cnt = bfs(sang, fireLocate);
		if (cnt != -1)
			cout << cnt << '\n';
		else
			cout << "IMPOSSIBLE\n";
	}
	return 0;
}
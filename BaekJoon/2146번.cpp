#include<bits/stdc++.h>
using namespace std;
#define MAX 101
int _map[MAX][MAX];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
bool visited[MAX][MAX];
int n;
void fill_map(int y, int x, int cnt) {
	_map[y][x] = cnt;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || _map[ny][nx] != -1) continue;
		fill_map(ny, nx, cnt);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> _map[i][j];
			if (_map[i][j])
				_map[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (_map[i][j] == -1) {
				fill_map(i, j, cnt);
				cnt++;
			}
		}
	}
	int min_dist = 987654321;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (_map[i][j] != 0) {
				visited[i][j] = true;
				cnt = 0;
				bool flag = false;
				int tmp = _map[i][j];
				queue<pair<int, int>> q;
				q.push({ i * 1000 + j, cnt });
				while (!q.empty()) {
					int y, x, dist;
					y = q.front().first / 1000, x = q.front().first % 1000, dist = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] || _map[ny][nx] == tmp)continue;
						if (_map[ny][nx] != 0 && _map[ny][nx] != tmp) {
							flag = true;
							min_dist = min(min_dist, dist);
							break;
						}
						q.push({ ny * 1000 + nx, dist + 1 });
						visited[ny][nx] = true;
					}
					if (flag)break;
				}
				memset(visited, 0, sizeof(visited));
			}
			else continue;
		}
	}
	cout << min_dist << '\n';
	return 0;
}
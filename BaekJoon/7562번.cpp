#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
bool visited[310][310];
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { 2,1,-1,-2,-2,-1,1,2 };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		memset(visited, 0, sizeof(visited));
		int l, y1, x1, y2, x2, cnt = 0;
		cin >> l;
		cin >> y1 >> x1 >> y2 >> x2;
		queue<pair<int, int>> q;
		visited[y1][x1] = true;
		q.push({ y1 * 1000 + x1 , cnt });
		while (!q.empty()) {
			int y, x, tmp;
			y = q.front().first / 1000, x = q.front().first % 1000;
			tmp = q.front().second;
			q.pop();
			if (y == y2 && x == x2) {
				cnt = tmp;
				break;
			}
			for (int i = 0; i < 8; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (0 > ny || ny >= l || nx < 0 || nx >= l || visited[ny][nx]) continue;
				q.push({ ny * 1000 + nx, tmp + 1 });
				visited[ny][nx] = true;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
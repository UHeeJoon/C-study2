#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
constexpr int dx[] = { 0,1,0,-1 };
constexpr int dy[] = { 1,0,-1,0 };
static void bfs(vector<vector<int>>& v, const int n, const int m, const int p_x, const int p_y) {
	queue<pair<int, int>> q;
	q.push({ p_x * 10000 + p_y, 0 });
	while (!q.empty()) {
		int x = q.front().first / 10000;
		int y = q.front().first % 10000;
		int visit = q.front().second;
		q.pop();
		if (v[x][y] > 2) {
			cout << "TAK\n" << visit << '\n';
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || v[nx][ny] == 1) { continue; }
			if (!v[nx][ny]) {
				v[nx][ny] = 1;
			}
			q.push({ nx * 10000 + ny, visit + 1 });
		}
	}
	cout << "NIE\n";
}
int main()
{
	FAST_IO;
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 0));
	int x{ 0 }, y{ 0 };
	char num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num;
			if (num == '2') {
				v[x = i][y = j] = 1;
			}
			else {
				v[i][j] = num - '0';
			}
		}
	}
	bfs(v, n, m, x, y);
	return 0;
}
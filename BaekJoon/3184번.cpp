#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;
#define MAX 251
int n, m, v, o;
char ground[251][251];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
pair<int, int> dfs(int y, int x, int sheep, int wolf) {
	if (ground[y][x] == 'o') sheep += 1;
	if (ground[y][x] == 'v') wolf += 1;
	ground[y][x] = '#';
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || ground[ny][nx]=='#')continue;
		tie(sheep, wolf) = dfs(ny, nx, sheep, wolf);
	}
	return { sheep, wolf };
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ground[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ground[i][j] != '#') {
				pair<int, int> temp = dfs(i, j, 0, 0);
				temp.first > temp.second ? o += temp.first : v += temp.second;
			}
		}
	}
	cout << o << " " << v << "\n";
}
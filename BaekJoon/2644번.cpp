#include<iostream>
#include<vector>
using namespace std;
vector<int> vi[101];
bool visited[101];
int n, p1, p2, m, cnt = 0;
void dfs(int y, int ret) {
	if (y == p2) {
		cnt = ret;
		return;
	}
	visited[y] = true;
	for (int i = 0; i < (int)vi[y].size(); i++) {
		int x = vi[y][i];
		if (!visited[x]) {
			dfs(x, ret + 1);
		}
	}
	return;
}
int main() {
	cin >> n >> p1 >> p2 >> m;
	for (int i = 0; i < m; i++) {
		int y, x; cin >> y >> x;
		vi[y].push_back(x);
		vi[x].push_back(y);
	}
	dfs(p1 , cnt);
	cnt = cnt == 0 ? -1 : cnt;
	cout << cnt << "\n";
}
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int board[6][6];
string s;
vector<string> v;
bool visited[6][6];
void dfs(int y, int x) {
	if ((int)s.length() == 6) {
		cout << s << "\n";
		if (find(v.begin(), v.end(), s) == v.end())
			v.push_back(s);
		s = "";
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5 || visited[ny][nx]) continue;
		if (!visited[y][x])
			visited[y][x] = 1;
		s += to_string(board[y][x]);
		dfs(ny, nx);
		visited[y][x] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			dfs(i, j);
	cout << (int)v.size() << "\n";
	return 0;
}
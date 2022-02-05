#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, _map[26][26], cnt;
string s;
vector<int> v;
void dfs(int y, int x) {
	_map[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || _map[ny][nx]==0) continue;
		dfs(ny, nx);
	}
	cnt += 1;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			_map[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (_map[i][j]) {
				dfs(i, j);
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < (int)v.size(); i++)
		cout << v[i] << "\n";
}
#include<bits/stdc++.h>
using namespace std;
int r, c, cnt, len;
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
char woods[51][51];
bool flag;
queue<int> water, sudal;
void WaterBfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c || woods[ny][nx]=='X' || woods[ny][nx]=='D' || woods[ny][nx]=='*') continue;
		woods[ny][nx] = '*';
		water.push(ny * 100 + nx);
	}
}
bool S_Bfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (woods[ny][nx] == 'D')
			return 1;
		if (ny < 0 || ny >= r || nx < 0 || nx >= c || woods[ny][nx]=='*' || woods[ny][nx] == 'X' || woods[ny][nx] == 'S') continue;
		woods[ny][nx] = 'S';
		sudal.push(ny * 100 + nx);
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> woods[i][j];
			if (woods[i][j] == '*')
				water.push(i * 100 + j);
			if (woods[i][j] == 'S')
				sudal.push(i * 100 + j);
		}
	}
	while (!sudal.empty()) {
		len = (int)water.size();
		for (int i = 0; i < len; i++) {
			WaterBfs(water.front() / 100, water.front() % 100);
			water.pop();
		}
		len = (int)sudal.size();
		for (int j = 0; j < len; j++) {
			flag = S_Bfs(sudal.front() / 100, sudal.front() % 100);
			if (flag)
				break;
			sudal.pop();
		}
		if (flag)
			break;
		cnt++;
	}
	if (sudal.empty())
		cout << "KAKTUS" << '\n';
	else
		cout << cnt + 1 << '\n';
	return 0;
}
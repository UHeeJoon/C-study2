#include<bits/stdc++.h>
using namespace std;
int r, c, S, EndPoind, cnt = 5;
int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
char woods[51][51];
bool visited[51][51];
vector<int> v;
void WaterBfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx] || woods[ny][nx]=='X' || woods[ny][nx]=='D') continue;
		woods[ny][nx] = '*';
		v.push_back(ny * 100 + nx);
	}
}
int S_Bfs() {
	int y = S / 100, x = S % 100;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c || woods[ny][nx]=='*' || woods[ny][nx] == 'X') continue;
		if(woods[ny][nx] == 'D')
		S = ny * 100 + nx;
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> woods[i][j];
			if (woods[i][j] == 'S')
				S = i * 100 + j;
			if (woods[i][j] == '*')
				v.push_back(i * 100 + j);
		}
	}
	int i = 0;
	while (cnt) {
		int len = (int)v.size();
		for (i; i < len; i++) 
			WaterBfs(v[i] / 100, v[i] % 100);


		cnt--;
	}

	return 0;
}
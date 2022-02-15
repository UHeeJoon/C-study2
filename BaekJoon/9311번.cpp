#include<iostream>
#include<queue>
using namespace std;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
int t, r, c, temp, way[16][16];
char robot[16][16];
void Clear() {
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++) {
			robot[i][j] = ' ';
			way[i][j] = 0;
		}
}
int bfs(int n) {
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int y = q.front() / 100;
		int x = q.front() % 100;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c || way[ny][nx] != 0 || robot[ny][nx] == 'X') continue;
			if (robot[ny][nx] == 'G') 
				return way[y][x];
			way[ny][nx] = way[y][x] + 1;
			q.push(ny * 100 + nx);
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> robot[i][j];
				if (robot[i][j] == 'S')
					temp = i * 100 + j;
			}

		}
		temp = bfs(temp);
		if (temp != -1)
			cout << "Shortest Path: " << temp + 1 << "\n";
		else
			cout << "No Exit\n";
		Clear();
	}
	return 0;
}
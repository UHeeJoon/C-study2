#include<iostream>
#include<algorithm>
using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool visited[26];
char board[21][21];
int R, C, sum;
void dfs(int y, int x, int cnt) {
	if (visited[board[y][x] - 'A']) return ;
	sum = max(sum, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];	
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)continue;
		if(visited[board[y][x] - 'A'] == 0)
			visited[board[y][x] - 'A'] = 1;
		dfs(ny, nx, cnt + 1);
		visited[board[y][x] - 'A'] = 0;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)	
			cin >> board[i][j];
	dfs(0, 0, 1);
	cout << sum << "\n";
	return 0;
}
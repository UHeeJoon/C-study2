#include<iostream>
using namespace std;
int R, C, K, tmp;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool visited[7][7];
char way[7][7];
void dfs(int y, int x, int cnt) {
	if (visited[y][x]) return;
	if (cnt == K && (y==0 &&x== C -1))
		tmp += 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C || way[ny][nx] =='T')continue;
		
		if (visited[y][x] == 0)
			visited[y][x] = 1;
		dfs(ny, nx, cnt + 1);
		visited[y][x] = 0;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> way[i][j];
	dfs(R - 1, 0, 1);
	cout << tmp << "\n";
}
/*
#include<iostream>
#include<string>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, k, visited[10][10];
char a[10][10];
string s;
int go(int y, int x){
	if(y == 0 && x == m - 1){
		if(k == visited[y][x]) return 1;
		return 0;
	}
	int ret = 0;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || a[ny][nx] == 'T')continue;
		visited[ny][nx] = visited[y][x] + 1;
		ret += go(ny, nx);
		visited[ny][nx] = 0;
	}
	return ret;
}
int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			a[i][j] = s[j];
		}
	}
	visited[n - 1][0] = 1;
	cout << go(n - 1, 0) << "\n";
}
*/
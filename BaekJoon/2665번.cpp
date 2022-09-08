#include<bits/stdc++.h>
using namespace std;
#define MAX 55
#define INF 2'100'000'000
//#define MOD 1'000'000'007
//typedef long long ll;
int n;
bool arr[MAX][MAX];
int dist[MAX][MAX];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int bfs(int r, int c) {
	fill(&dist[0][0], &dist[0][0] + MAX * MAX, INF);
	dist[r][c] = 0;
	queue<pair<pair<int, int>, int>> q;
	q.push({ {r, c}, 0 });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny <= 0 || ny > n || nx <= 0 || nx > n)continue;
			int nCnt = cnt + (arr[ny][nx] == 0 ? 1 : 0);
			if (nCnt >= dist[ny][nx]) continue;
			q.push({ {ny, nx}, nCnt });
			dist[ny][nx] = nCnt;
		}

	}
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		cout << dist[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	return dist[n][n];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char a; cin >> a;
			arr[i][j] = a - '0';
		}
	}
	cout << bfs(1, 1) << '\n';
	return 0;
}
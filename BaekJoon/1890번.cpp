#include<bits/stdc++.h>
using namespace std;
#define MAX 110
int GAME[MAX][MAX], n;
long long dp[MAX][MAX];
int dy[] = { 0,1 };
int dx[] = { 1,0 };
void check(int y, int x, int cnt) {
	for (int i = 0; i < 2; i++) {
		int ny = y + dy[i] * cnt;
		int nx = x + dx[i] * cnt;
		if (ny <1 || ny >n || nx <1 || nx >n)continue;
		if (!cnt) continue;
		dp[ny][nx] += dp[y][x];
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> GAME[i][j];
			check(i, j, GAME[i][j]);
		}
	}
	cout << dp[n][n] << '\n';
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int board[102][102];
ll dp[102][102];
int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> board[i][j];
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) continue;
			if (i + board[i][j] < N) dp[i + board[i][j]][j] += dp[i][j];
			if (j + board[i][j] < N) dp[i][j + board[i][j]] += dp[i][j];
		}
	}
	cout << dp[N - 1][N - 1];
}
*/
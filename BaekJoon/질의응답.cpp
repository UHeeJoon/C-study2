#pragma warning(disable : 4996)
#include<bits/stdc++.h>
using namespace std;
#define MAX 17
#define INF 2147483647
bool board[MAX][MAX];
bool tmpBoard[MAX][MAX];
int tmp[4];
int n, m, d;
int _max = 0;
bool check(int aY, int aX, int eY, int eX) {
	return abs(aY - eY) + abs(aX - eX) <= d;
}
bool allEnemyKill() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (tmpBoard[i][j])return true;
	return false;
}
void moveBoard() {
	for (int i = n; i > 0; i--) {
		for (int j = 1; j <= m; j++) {
			tmpBoard[i][j] = tmpBoard[i - 1][j];
			tmpBoard[i - 1][j] = false;
		}
	}
	return;
}
void boardCopy() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			tmpBoard[i][j] = board[i][j];
	return;
}
void killEnemy() {
	int cnt = 0;
	boardCopy();
	while (allEnemyKill()) {
		for (int i = 1; i <= 3; i++) {
			int archerY = n + 1;
			int archerX = tmp[i];
			bool kill = false;
			for (int j = 0; j < d; j++) {
				int enemyY = n - j;
				int enemyX = m;
				int k = 0;
				while(enemyX - k >=1 || enemyX + k <= m) {
					if (enemyX - k >= 1) {
						if (tmpBoard[enemyY][enemyX - k] && check(archerY, archerX, enemyY, enemyX - k)) {
							tmpBoard[enemyY][enemyX - k] = false;
							kill = true;
							cnt++;
							break;
						}
					}
					if (enemyX + k <= m) {
						if (tmpBoard[enemyY][enemyX + k] && check(archerY, archerX, enemyY, enemyX + k)) {
							tmpBoard[enemyY][enemyX + k] = false;
							kill = true;
							cnt++;
							break;
						}
					}
					k++;
				}
				if (kill)break;
			}
		}
		moveBoard();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				cout << tmpBoard[i][j];
			cout << '\n';
		}
		cout << '\n';
	}

	//cout << cnt << '\n';
	_max = max(_max, cnt);
	return;
}
void dfs(int start,int idx, int cnt) {
	if (idx == cnt + 1) {
		//for (int i = 1; i <= cnt; i++) {
		//	cout << tmp[i] << ' ';
		//}
		//cout << '\n';
		killEnemy();
		return;
	}
	for (int i = start; i <= m; i++) {
		tmp[idx] = i;
		dfs(i + 1, idx + 1, cnt);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}
	dfs(1,1, 3);
	cout << _max << '\n';
	return 0;
}

/*

15 15 10
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

*/
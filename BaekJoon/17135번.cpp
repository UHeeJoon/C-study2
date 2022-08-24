#include<bits/stdc++.h>
using namespace std;
#define MAX 17
#define INF 2147483647
bool board[MAX][MAX];
bool tmpBoard[MAX][MAX];
int tmp[4];
int n, m, d;
int _max = 0;
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.second <= b.second) {
		if (a.second == b.second) {
			if (a.first.second < b.first.second)
				return true;
			return false;
		}
		return true;
	}
	return false;
}
int check(int aY, int aX, int eY, int eX) {
	return abs(aY - eY) + abs(aX - eX);
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
		pair<int, int> p[4] = { {0,0}, };
		for (int i = 1; i <= 3; i++) {
			vector<pair<pair<int, int>, int>> dead;
			int archerY = n + 1;
			int archerX = tmp[i];
			for (int j = 0; j < d; j++) {
				int enemyY = n - j;
				int enemyX = 1;
				for (enemyX; enemyX <= m; enemyX++) {
					int dist = check(archerY, archerX, enemyY, enemyX);
					if (tmpBoard[enemyY][enemyX] && dist <= d) {
						dead.push_back({ { enemyY , enemyX }, dist });
					}
				}
			}
			if (dead.size() >= 1) {
				sort(dead.begin(), dead.end(), comp);
				p[i].first = dead[0].first.first;
				p[i].second = dead[0].first.second;
			}
			else {
				p[i].first = 0;
				p[i].second = 0;
			}

		}
		//for (auto a : dead)
		//	cout << a.first.first << ' ' << a.first.second << ' ' << a.second << '\n';
		//cout << '\n';
		for (int i = 1; i <= 3; i++) {
			if (p[i].first == 0 && p[i].second == 0)continue;
			if (tmpBoard[p[i].first][p[i].second]) {
				tmpBoard[p[i].first][p[i].second] = false;
				cnt++;
			}
		}
		//cout << cnt << '\n';
		//for (int i = 1; i <= n; i++) {
		//	for (int j = 1; j <= m; j++)
		//		cout << tmpBoard[i][j];
		//	cout << '\n';
		//}
		//cout << '\n';
		moveBoard();
	}

	//cout << cnt << '\n';
	_max = max(_max, cnt);
	return;
}
void dfs(int start, int idx, int cnt) {
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
	dfs(1, 1, 3);
	cout << _max << '\n';
	return 0;
}
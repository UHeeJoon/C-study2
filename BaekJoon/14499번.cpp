#include<bits/stdc++.h>
using namespace std;
#define MAX 25
#define INF 2147483647
int dy[] = { 0, 0, 0, -1, 1 };
int dx[] = { 0, 1, -1, 0, 0 };
int n, m, x, y, k;
int _map[MAX][MAX];
int dice[7];
// dice[1] = 맨 아래, dice[2] = 동쪽, dice[3] = 서쪽, dice[4]= 북쪽, dice[5] = 남쪽, dice[6] = 맨 위에 
void change(int direction) {
	int tmpDice[7] = { 0, };
	copy(dice, dice + 7, tmpDice);
	switch (direction) {
	case 1: // 동
		dice[1] = tmpDice[2];
		dice[2] = tmpDice[6];
		dice[3] = tmpDice[1];
		dice[6] = tmpDice[3];
		break;
	case 2:	// 서
		dice[1] = tmpDice[3];
		dice[2] = tmpDice[1];
		dice[3] = tmpDice[6];
		dice[6] = tmpDice[2];
		break;
	case 3:	// 북
		dice[1] = tmpDice[4];
		dice[4] = tmpDice[6];
		dice[5] = tmpDice[1];
		dice[6] = tmpDice[5];
		break;
	case 4:	// 남
		dice[1] = tmpDice[5];
		dice[4] = tmpDice[1];
		dice[5] = tmpDice[6];
		dice[6] = tmpDice[4];
		break;
	}
	return;
}
void move(int movement) {
	int ny = y + dy[movement];
	int nx = x + dx[movement];
	if (ny < 0 || ny >= n || nx < 0 || nx >= m) return;
	y = ny; x = nx;
	change(movement);
	cout << dice[6] << '\n';
	if (_map[y][x] == 0) {
		_map[y][x] = dice[1];
	}
	else {
		dice[1] = _map[y][x];
		_map[y][x] = 0;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> _map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int movement; cin >> movement;
		move(movement);
	}
	return 0;
}
#include<iostream>
#include<queue>
using namespace std;
int N, M;
char board[16][16];
bool visited[16][16];
bool check(int y, int x) {
	return board[y][x] == '#' && visited[y][x] == 0;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	int tmp = 1, flag = N < M ? N : M;
	while (1) {
		if (tmp == flag - tmp) break;
		for (int i = tmp; i < N - tmp; i++) {
			for (int j = tmp; j < M - tmp; j++) {
				if (board[i][j] == '#' && visited[i][j] == 0) {
					if (check(i, j + tmp) && check(i + tmp, j) && check(i, j - tmp) && check(i - tmp, j)) {
						tmp++;
					}
					cout << tmp << " ";
				}
			}
		}
	}
}

// board[i][j + tmp] == '#' && board[i + tmp][j] == '#' && board[i][j - tmp] == '#' && board[i - tmp][j] == '#'

/*
#####
#####
#####
#####
#####
*/
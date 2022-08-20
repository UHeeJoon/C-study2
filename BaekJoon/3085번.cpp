#include<bits/stdc++.h>
using namespace std;
#define MAX 55
#define INF 2147483647
char board[MAX][MAX];
int n;
int rowCheck(int row) {
	int rowCnt = 1, rowTmp = 1;
	for (int i = 1; i < n; i++) {
		if (board[row][i] == board[row][i + 1])rowTmp++;
		else {
			rowCnt = max(rowCnt, rowTmp);
			rowTmp = 1;
		}
	}
	return max(rowCnt, rowTmp);
}
int colCheck(int col) {
	int colCnt = 1, colTmp = 1;
	for (int i = 1; i < n; i++) {
		if (board[i][col] == board[i + 1][col])colTmp++;
		else {
			colCnt = max(colCnt, colTmp);
			colTmp = 1;
		}
	}
	return max(colCnt, colTmp);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int rowCnt = 0, colCnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != n) {
				colCnt = max(colCnt, colCheck(j));
				swap(board[i][j], board[i + 1][j]);
				rowCnt = max({ rowCnt, rowCheck(i), rowCheck(i + 1) });
				colCnt = max(colCnt, colCheck(j));
				swap(board[i][j], board[i + 1][j]);
			}
			if (j != n) {
				rowCnt = max(rowCnt, rowCheck(i));
				swap(board[i][j], board[i][j + 1]);
				colCnt = max({ colCnt, colCheck(j), colCheck(j + 1) });
				rowCnt = max(rowCnt, rowCheck(i));
				swap(board[i][j], board[i][j + 1]);
			}
		}
	}
	cout << max(rowCnt, colCnt) << '\n';
	return 0;
}
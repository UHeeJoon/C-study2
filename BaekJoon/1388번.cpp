#include<bits/stdc++.h>
using namespace std;
#define MAX 52
char board[MAX][MAX];
bool visited[MAX][MAX];
int row, col, n, m;
void dfs(char floor, int y, int x) {
    if (floor != board[y][x] || visited[y][x] || y < 0 || y >= n || x < 0 || x >= m) return;
    visited[y][x] = true;
    if (floor == '-') {
        dfs(floor, y, x + 1);
    }
    else
        dfs(floor, y + 1, x);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                if (board[i][j] == '-') {
                    dfs(board[i][j], i, j);
                    row++;
                }
                else {
                    dfs(board[i][j], i, j);
                    col++;
                }
            }
        }
    }
    cout << row + col << '\n';
    return 0;
}
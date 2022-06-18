#include<bits/stdc++.h>
using namespace std;
int _map[50][50];
bool visited[50][50];
int N, M;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
void dfs(int r, int c, int d, int sum) {
    for (int i = 0; i < 4; i++) {
        int nd = (d + 3 - i) % 4;
        int nr = r + dr[nd];
        int nc = c + dc[nd];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M || _map[nr][nc] == 1) {
            continue;
        }
        if (!visited[nr][nc] && !_map[nr][nc]) {
            visited[nr][nc] = true;
            dfs(nr, nc, nd, sum + 1);
        }
    }
    int backIdx = d + 2 < 4 ? d + 2 : d - 2;
    int backr = r + dr[backIdx];
    int backc = c + dc[backIdx];
    if (0 <= backr && backr < N && 0 <= backc && backc < M) {
        if (_map[backr][backc] == 0) {
            dfs(backr, backc, d, sum);
        }
        else {
            cout << sum << '\n';
            exit(0);
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int r, c, d;
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            cin >> _map[i][j];
    visited[r][c] = true;
    dfs(r, c, d, 1);
    return 0;
}
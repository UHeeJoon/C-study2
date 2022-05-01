#include<bits/stdc++.h>
using namespace std;
#define MAX 260
char _map[MAX][MAX];
int n, m, v, k;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
void bfs(int a, int b) {
    int v_cnt = 0, k_cnt = 0;
    queue<int> q; q.push(a * 1000 + b);
    while (!q.empty()) {
        int y = q.front() / 1000;
        int x = q.front() % 1000;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || _map[ny][nx] == '#')continue;
            if (_map[ny][nx] == 'v')
                v_cnt++;
            if (_map[ny][nx] == 'k')
                k_cnt++;
            _map[ny][nx] = '#';
            q.push(ny * 1000 + nx);
        }
    }
    if (v_cnt >= k_cnt)
        k -= k_cnt;
    else
        v -= v_cnt;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> _map[i][j];
            if (_map[i][j] == 'v')
                v++;
            if (_map[i][j] == 'k')
                k++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bfs(i, j);
        }
    }
    cout << k << ' ' << v << '\n';
    return 0;
}
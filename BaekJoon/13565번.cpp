#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
#define MAX 1001
char _map[MAX][MAX];
int n, m;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
bool bfs() {
    queue<int> q;
    for (int i = 0; i < m; i++)
        if (_map[0][i] == '0')
            q.push(i);
    while (!q.empty()) {
        int y = q.front() / 10000;
        int x = q.front() % 10000;
        if (y == n - 1)
            return true;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || _map[ny][nx] == '1')continue;
            _map[ny][nx] = '1';
            q.push(ny * 10000 + nx);
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> _map[i][j];
        }
    }
    cout << (bfs() ? "YES\n" : "NO\n");
    return 0;
}
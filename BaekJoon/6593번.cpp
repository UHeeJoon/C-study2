#include<bits/stdc++.h>
using namespace std;
int l, r, c;
char arr[35][35][35];
bool visited[35][35][35];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
struct Q {
    int y;
    int x;
    int z;
};
int bfs(int y, int x, int z) {
    visited[z][y][x] = true;
    queue<pair<Q, int>> q;
    q.push({ {y, x, z}, 0 });
    while (!q.empty()) {
        Q cur = q.front().first;
        int time = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++) {
            Q next = { cur.y + dy[i], cur.x + dx[i], cur.z + dz[i] };
            if (next.x < 0 || next.x >= c || next.y < 0 || next.y >= r || next.z < 0 || next.z >= l || arr[next.z][next.y][next.x] == '#')continue;
            if (arr[next.z][next.y][next.x] == 'E') return time + 1;
            if (arr[next.z][next.y][next.x] == '.' && !visited[next.z][next.y][next.x]) {
                q.push({ next, time + 1 });
                visited[next.z][next.y][next.x] = true;
            }
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (1) {
        int y = 0, x = 0, z = 0;
        cin >> l >> r >> c;
        if (!l && !r && !c)break;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    cin >> arr[i][j][k];
                    if (arr[i][j][k] == 'S') {
                        z = i, y = j, x = k;
                    }
                }
            }
        }
        int ans = bfs(y, x, z);
        if (ans)
            cout << "Escaped in " << ans << " minute(s).\n";
        else
            cout << "Trapped!\n";
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int _map[51][51], times[51][51];
bool check[11];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
vector<int> virus;
int n, m, result = 987654321, zero = 0;
void bfs(queue<int> q) {
    int _min = 0, empty_place = 0;
    while (!q.empty()) {
        int y = q.front() / 100;
        int x = q.front() % 100;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n || _map[ny][nx] == 1 || times[ny][nx] != -1) continue;
            times[ny][nx] = times[y][x] + 1;
            q.push(ny * 100 + nx);
            if (_map[ny][nx] == 0) {
                empty_place++;
                _min = times[ny][nx];
            }
        }
    }
    if (zero == empty_place)
        result = min(result, _min);
}
void dfs(int num, int cnt) {
    if (cnt == m) {
        queue<int> q;
        memset(times, -1, sizeof(times));
        for (int i = 0; i < virus.size(); i++) {
            if (check[i]) {
                q.push(virus[i]);
                times[(virus[i] / 100)][(virus[i] % 100)] = 0;
            }
        }
        bfs(q);
        return;
    }
    for (int i = num; i < virus.size(); i++) {
        if (!check[i]) {
            check[i] = true;
            dfs(i + 1, cnt + 1);
            check[i] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> _map[i][j];
            if (_map[i][j] == 2)
                virus.push_back(i * 100 + j);
            else if (_map[i][j] == 0)
                zero++;
        }
    }
    dfs(0, 0);
    cout << (result == 987654321 ? -1 : result) << '\n';
    return 0;
}
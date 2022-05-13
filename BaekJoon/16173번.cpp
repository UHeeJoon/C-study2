#include<bits/stdc++.h>
using namespace std;
int GAME[5][5];
bool visited[5][5];
int n;
void dfs(int y, int x) {
    if (y<1 || y>n || x<1 || x>n || visited[y][x])return;
    if (y == n && x == n) {
        cout << "HaruHaru\n";
        exit(0);
    }
    if (!visited[y][x]) {
        visited[y][x] = true;
        dfs(y, x + GAME[y][x]);
        dfs(y + GAME[y][x], x);
        visited[y][x] = false;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> GAME[i][j];
    dfs(1, 1);
    cout << "Hing\n";
    return 0;
}
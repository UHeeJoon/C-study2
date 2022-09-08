#include<bits/stdc++.h>
using namespace std;
#define MAX 1030
//#define INF 60'000'000'000
//#define MOD 1'000'000'007
//typedef long long ll;
int n, m;
int table[MAX][MAX];
int tree[MAX][MAX];
void update(int r, int c, int num) {
    for (int row = r; row <= n + 1; row += (row & -row))
        for (int col = c; col <= n + 1; col += (col & -col))
            tree[row][col] += num;

}
int sum(int r, int c) {
    int result = 0;
    for (int row = r; row > 0; row -= (row & -row))
        for (int col = c; col > 0; col -= (col & -col))
            result += tree[row][col];
    return result;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> table[i][j];
            update(i, j, table[i][j]);
        }
    }
    int w, r1, c1, r2, c2, num;
    while (m--) {
        cin >> w;
        if (w == 0) {
            cin >> r1 >> c1 >> num;
            update(r1, c1, num - table[r1][c1]);
            table[r1][c1] = num;
        }
        else {
            cin >> r1 >> c1 >> r2 >> c2;
            cout << sum(r2, c2) - sum(r2, c1 - 1)
                - sum(r1 - 1, c2) + sum(r1 - 1, c1 - 1) << '\n';
        }
    }
    return 0;
}
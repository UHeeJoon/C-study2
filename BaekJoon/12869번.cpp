#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int INF = 987654321;
int a[3], n, visited[64][64][64];
int _a[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 3, 9},
    {1, 9, 3}
};
struct A {
    int a, b, c;
};
queue<A>q;
int solve(int a, int b, int c) {
    visited[a][b][c] = 1;
    q.push({ a, b, c });
    while (q.size()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if (visited[0][0][0]) break;
        for (int i = 0; i < 6; i++) {
            int na = max(0, a - _a[i][0]);
            int nb = max(0, b - _a[i][1]);
            int nc = max(0, c - _a[i][2]);
            // index가 음수가 되는것을 방지하기 위한 코드
            if (visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({ na, nb, nc });
        }
    }
    return visited[0][0][0] - 1;
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << solve(a[0], a[1], a[2]) << "\n";
    return 0;
}
/*
#include <iostream>
#include <algorithm>//min
#include <cstring>//memset
using namespace std;

int N;
int DP[61][61][61];
int HP[3] = { 0, };//SCV없으면 그냥 0

int solution(int x, int y, int z) {
    //파괴된 SCV가 있을 경우
    if (x < 0)return solution(0, y, z);
    if (y < 0)return solution(x, 0, z);
    if (z < 0)return solution(x, y, 0);

    //모든 SCV가 파괴된 경우
    if (x == 0 && y == 0 && z == 0)
        return 0;

    int& res = DP[x][y][z];

    //이미 구해둔 값이면
    if (res != -1)
        return res;

    res = 99999999;
    res = min(res, solution(x - 9, y - 3, z - 1) + 1);
    res = min(res, solution(x - 9, y - 1, z - 3) + 1);
    res = min(res, solution(x - 3, y - 9, z - 1) + 1);
    res = min(res, solution(x - 1, y - 9, z - 3) + 1);
    res = min(res, solution(x - 3, y - 1, z - 9) + 1);
    res = min(res, solution(x - 1, y - 3, z - 9) + 1);

    return res;
}

int main() {
    cin >> N;
    memset(DP, -1, sizeof(DP));
    for (int i = 0; i < N; i++) {
        cin >> HP[i];
    }
    cout << solution(HP[0], HP[1], HP[2]) << '\n';

    return 0;
}
*/
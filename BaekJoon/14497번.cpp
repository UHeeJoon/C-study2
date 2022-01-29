#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
char a[301][301];
int n, m, x1, y1, x2, y2;
int visited[301][301];
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };
int ret;
queue<int> q;
int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    y1--, x1--, y2--, x2--;
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    q.push(1000 * y1 + x1);
    // 2차원 좌표를 변수로 생성
    visited[y1][x1] = 1;
    int cnt = 0;
    while (a[y2][x2] != '0') {
        cnt++;
        queue<int> temp;
        while (q.size()) {
            int y = q.front() / 1000;
            int x = q.front() % 1000;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
                visited[ny][nx] = cnt;
                if (a[ny][nx] != '0') {
                    // 1만나면 0으로 바꾸고 temp에 삽입 q로 인한 while문을 종료하기 위해
                    a[ny][nx] = '0';
                    temp.push(1000 * ny + nx);
                }
                else q.push(1000 * ny + nx);
                // 1만날 때 까지 q에 푸쉬하면서 무한 루프
            }
        }
        q = temp;
    }
    printf("%d\n", visited[y2][x2]);
}
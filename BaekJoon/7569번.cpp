#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
#define MAX 102 
int M, N, H;
int days = 0;
int tomato = 0;
bool flag = false;
int arr[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int dx[] = { 0,0,1,-1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
queue<tuple<int, int, int>> q;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 0) tomato++;
                if (arr[i][j][k] == 1) {
                    q.push({ i,j,k });
                    visited[i][j][k] = true;
                }
            }
        }
    }
    if (tomato == 0) {
        cout << tomato;
        return 0;
    }
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int a = get<0>(q.front());
            int b = get<1>(q.front());
            int c = get<2>(q.front());
            q.pop();
            for (int i = 0; i < 6; i++) {
                int na = a + dx[i];
                int nb = b + dy[i];
                int nc = c + dz[i];
                if (na >= 0 && nb >= 0 && nc >= 0 && H > na && N > nb && M > nc && !visited[na][nb][nc] && arr[na][nb][nc] == 0) {
                    q.push({ na,nb,nc });
                    visited[na][nb][nc] = visited[a][b][c] + 1; tomato--;
                }
            }
        } days++;
    }
    if (tomato > 0) {
        cout << -1;
    }
    else {
        cout << days - 1;
    }
}

/*
#include <bits/stdc++.h>
using namespace std;

typedef struct {
        int x, y, z;
        int cnt;
} types;

int M, N, H; //가로 세로 높이
int box[101][101][101];
bool visited[101][101][101];
int moveX[6] = {1, -1, 0, 0, 0, 0};
int moveY[6] = {0, 0, 1, -1, 0, 0};
int moveZ[6] = {0, 0, 0, 0, 1, -1};
queue<types> bfs;

int main(void) {
        int cnt = 0;

        scanf("%d %d %d", &M, &N, &H);
        for (int k = 0; k < H; k++)
                for (int i = 0; i < N; i++)
                        for (int j = 0; j < M; j++) {
                                scanf("%d", &box[i][j][k]);
                                if (box[i][j][k] == 1) {
                                        bfs.push({i, j, k, 0});
                                        visited[i][j][k] = true;
                                }
                                else if (box[i][j][k] == -1)
                                        visited[i][j][k] = true;
                        }
        if (bfs.empty()) {
                printf("-1");
                return 0;
        }

        while (!bfs.empty()) {
                auto a = bfs.front();
                bfs.pop();
                cnt = max(cnt, a.cnt);

                for (int i = 0; i < 6; i++) {
                        int nx = a.x + moveX[i];
                        int ny = a.y + moveY[i];
                        int nz = a.z + moveZ[i];

                        if (nx >= 0 && ny >= 0 && nz >= 0 && nx < N && ny < M && nz < H && !visited[nx][ny][nz]) {
                                bfs.push({nx, ny, nz, a.cnt + 1});
                                visited[nx][ny][nz] = true;
                        }
                }
        }

        for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                        for(int k = 0; k < H; k++)
                                if (!visited[i][j][k]) {
                                        printf("-1");
                                        return 0;
                                }

        printf("%d", cnt);
        return 0;

}
*/

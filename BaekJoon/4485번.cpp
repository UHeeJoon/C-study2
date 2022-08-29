// 완전탐색 이용
#include<bits/stdc++.h>
#define MAX 130
#define INF 987654321
using namespace std;
int N, Answer;
int MAP[MAX][MAX];
int Visit[MAX][MAX];
bool Inp_Flag;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
void Initialize() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            Visit[i][j] = INF;
        }
    }
}
void Input() {
    cin >> N;
    if (N == 0) {
        Inp_Flag = true;
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
void Solution() {
    queue<pair<int, int>> Q;
    Q.push(make_pair(0, 0));
    Visit[0][0] = MAP[0][0];
    while (Q.empty() == 0) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (Visit[nx][ny] > Visit[x][y] + MAP[nx][ny])
                {
                    Visit[nx][ny] = Visit[x][y] + MAP[nx][ny];
                    Q.push(make_pair(nx, ny));
                }
            }
        }
    }
    Answer = Visit[N - 1][N - 1];
}
void Solve() {
    for (int T = 1; ; T++) {
        Initialize();
        Input();
        if (Inp_Flag == true) return;
        Solution();

        cout << "Problem " << T << ": " << Answer << endl;
    }
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}
/*
* // 다익스트라 이용
#include<iostream>
#include<queue>

#define endl "\n"
#define MAX 130
#define INF 987654321
using namespace std;
int N, Answer;
int MAP[MAX][MAX];
int Dist[MAX][MAX];
bool Inp_Flag;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
void Initialize(){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            Dist[i][j] = INF;
        }
    }
}
void Input(){
    cin >> N;
    if (N == 0){
        Inp_Flag = true;
        return;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
    }
}
void Solution(){
    priority_queue<pair<int, pair<int, int>>> PQ;
    PQ.push(make_pair(-MAP[0][0], make_pair(0, 0)));
    Dist[0][0] = MAP[0][0];
    while (PQ.empty() == 0){
        int Cost = -PQ.top().first;
        int x = PQ.top().second.first;
        int y = PQ.top().second.second;
        PQ.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N){
                int nCost = Cost + MAP[nx][ny];
                if (Dist[nx][ny] > nCost){
                    Dist[nx][ny] = nCost;
                    PQ.push(make_pair(-Dist[nx][ny], make_pair(nx, ny)));
                }
            }
        }
    }
    Answer = Dist[N - 1][N - 1];
}
void Solve()
{
    int Tc = 1;
    for (int T = 1; ; T++){
        Initialize();
        Input();
        if (Inp_Flag == true) return;
        Solution();
        cout << "Problem " << T << ": " << Answer << endl;
    }
}
int main(void){
    ios::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}
*/



/*
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int max_n = 130;
int N, INF = 987654321, a[max_n][max_n],dist[max_n][max_n], t;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    while(++t){
        scanf("%d", &N);
        if(N == 0)return 0;
        fill(&a[0][0], &a[0][0] + max_n * max_n, 0);
        fill(&dist[0][0], &dist[0][0] + max_n * max_n, INF);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &a[i][j]);
            }
        }
        pq.push(make_pair(a[0][0], 0));
        dist[0][0] = a[0][0];
        while(pq.size()){
            int herey = pq.top().second / 1000;
            int herex = pq.top().second % 1000;
            int here_dist = pq.top().first;
            pq.pop();
            if(dist[herey][herex] != here_dist) continue;
            for(int i = 0; i < 4; i++){
                int ny = herey + dy[i];
                int nx = herex + dx[i];
                if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                int _dist = a[ny][nx];
                if(dist[ny][nx] > dist[herey][herex] + _dist){
                    dist[ny][nx] = dist[herey][herex] + _dist;
                    pq.push(make_pair(dist[ny][nx], ny * 1000 + nx));
                }
            }
        }
        printf("Problem %d: %d\n", t, dist[N - 1][N - 1]);
    }
    return 0;
}
*/
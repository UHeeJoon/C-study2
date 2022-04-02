#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
int N;
int graph[MAX][MAX];
void floyd(void) {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];
    floyd();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << graph[i][j] << " ";
        cout << '\n';
    }
    return 0;
}

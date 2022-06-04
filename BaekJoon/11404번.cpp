#include<bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAX 100 + 1 
int vertex, edge;
int arr[MAX][MAX];
int from, to, weight;

void floyd() {
    for (int i = 1; i <= vertex; i++)
        for (int j = 1; j <= vertex; j++)
            for (int k = 1; k <= vertex; k++)
                if (arr[j][i] != INF && arr[i][k] != INF)
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> vertex >> edge;
    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            arr[i][j] = INF;
        }
    }
    for (int i = 0; i < edge; i++) {
        cin >> from >> to >> weight;
        if (arr[from][to] > weight)
            arr[from][to] = weight;
    }
    floyd();
    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            if (i == j || arr[i][j] == INF)
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
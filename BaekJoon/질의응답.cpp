#pragma warning (disable :4996)
#include<iostream>
#include<algorithm>
#define MAX 9
using namespace std;
int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };
void dfs(int num, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = num; i <= n; i++) {
        arr[cnt] = i;
        dfs(i, cnt + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL);
    cin >> n >> m;
    dfs(1, 0);
}
#include<bits/stdc++.h>
using namespace std;
#define MAX 32010
//#define INF 2147483647
//#define MOD 1'000'000'007
//typedef long long ll;
int n, m;
int arr[MAX];
vector<int> v[MAX];
void topologicalSort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0)
            q.push(i);
    }
    for (int i = 0; i < n; i++) {
        if (q.empty())return;
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for (int next : v[cur]) {
            arr[next]--;
            if (arr[next] == 0) {
                q.push(next);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v1, v2; cin >> v1 >> v2;
        v[v1].push_back(v2);
        arr[v2]++;
    }
    topologicalSort();
    return 0;
}
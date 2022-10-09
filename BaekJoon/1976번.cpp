#include<bits/stdc++.h>
using namespace std;
int n, m;
int parent[210];
int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}
void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int go; cin >> go;
            if (i >= j)continue;
            if (go == 1) {
                unionParent(i, j);
            }
        }
    }
    int tmp = 0;
    bool flag = false;
    for (int i = 1; i <= m; i++) {
        int connect; cin >> connect;
        if (i == 1)
            tmp = getParent(connect);
        else {
            if (tmp != getParent(connect))
                flag = true;
        }
    }
    if (flag)cout << "NO\n";
    else cout << "YES\n";
    return 0;
}
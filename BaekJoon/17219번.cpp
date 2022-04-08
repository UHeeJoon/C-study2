#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unordered_map<string, string> _map;
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s, s2; cin >> s >> s2;
        _map[s] = s2;
    }
    while (m--) {
        string s;
        cin >> s;
        cout << _map[s] << '\n';
    }
    return 0;
}

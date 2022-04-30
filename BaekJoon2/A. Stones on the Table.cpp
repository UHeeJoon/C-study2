#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    string s; cin >> s;
    int cnt(0);
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1])cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
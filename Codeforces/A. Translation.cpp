#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s, s2;
    cin >> s >> s2;
    reverse(s.begin(), s.end());
    cout << (s == s2 ? "YES\n" : "NO\n");
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    s[0] = s[0] > 96 ? s[0] - 32 : s[0];
    cout << s << '\n';
    return 0;
}
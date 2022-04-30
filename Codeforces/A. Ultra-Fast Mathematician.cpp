#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s, s2; cin >> s >> s2;
    string s3 = "";
    for (int i = 0; i < s.length(); i++)
        s3 += s[i] == s2[i] ? '0' : '1';
    cout << s3 << '\n';
    return 0;
}
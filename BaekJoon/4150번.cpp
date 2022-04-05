#include<bits/stdc++.h>
using namespace std;
string string_add(string s, string s2) {
    int sum = 0;
    string ret;
    while (s.size() || s2.size() || sum) {
        if (s.size()) {
            sum += s.back() - '0';
            s.pop_back();
        }
        if (s2.size()) {
            sum += s2.back() - '0';
            s2.pop_back();
        }
        ret += (sum % 10) + '0';
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    string s = "0", s1 = "1", ret = "";
    if (n == 0) cout << s << '\n';
    if (n == 1) cout << s1 << '\n';
    for (int i = 2; i <= n; i++) {
        ret = string_add(s, s1);
        s = s1, s1 = ret;
    }
    cout << ret << '\n';
    return 0;
}
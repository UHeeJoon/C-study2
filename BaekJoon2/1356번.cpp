#include<bits/stdc++.h>
using namespace std;
bool multi(string str1, string str2) {
    int sum = 1, sum2 = 1;
    while (str1.size() || str2.size()) {
        if (str1.size()) {
            sum *= str1.back() - '0';
            str1.pop_back();
        }
        if (str2.size()) {
            sum2 *= str2.back() - '0';
            str2.pop_back();
        }
    }
    return sum == sum2;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    bool flag = false;
    for (int i = 1; i < s.length(); i++) {
        if (multi(s.substr(0, i), s.substr(i))) { flag = true; break; }
    }
    cout << (flag ? "YES\n" : "NO\n");
    return 0;
}
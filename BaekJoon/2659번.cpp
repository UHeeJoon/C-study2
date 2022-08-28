#include<bits/stdc++.h>
using namespace std;
#define MAX 110
#define INF 2147483647
int clockNum(int n) {
    int ret = n;
    for (int i = 0; i < 3; i++) {
        n = n % 1000 * 10 + n / 1000;
        ret = min(ret, n);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    for (int i = 0; i < 4; i++) {
        char c; cin >> c;
        s += c;
    }
    int cn = clockNum(stoi(s));

    int ans = 0;
    for (int i = 1111; i <= cn; i++) {
        if (clockNum(i) == i) ans++;
    }

    cout << ans << '\n';
    return 0;
}
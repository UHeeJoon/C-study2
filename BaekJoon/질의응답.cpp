#pragma warning(disable :4996)
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 3;
    while (t--) {
        int h, m, s, h2, m2, s2; cin >> h >> m >> s >> h2 >> m2 >> s2;
        h = h2 - h, m = m2 - m, s = s2 - s;
        if (s < 0) s = 60 + s, m = m - 1;
        if (m < 0) m = 60 + m, h = h - 1;
        cout << h << ' ' << m << ' ' << s << '\n';
    }
    return 0;
}
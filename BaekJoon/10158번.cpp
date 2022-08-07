#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int w, h, p, q, t; cin >> w >> h >> p >> q >> t;
    if ((p + t) / w % 2 == 0) {
        cout << (p + t) % w << ' ';
    }
    else cout << w - (p + t) % w << ' ';

    if ((q + t) / h % 2 == 0) {
        cout << (q + t) % h << '\n';
    }
    else cout << h - (q + t) % h << '\n';
    return 0;
}
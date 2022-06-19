#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll N, w, d, sum;
    while (cin >> N >> w >> d >> sum && !cin.eof()) {
        ll fullWeight = N * (N - 1) / 2 * w;
        ll ans = (sum - fullWeight) / d;
        if (!ans) cout << N << '\n';
        else cout << -ans << '\n';
    }
    return 0;
}
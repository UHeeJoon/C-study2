#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t1, t2; cin >> t1 >> t2;
    int cnt = 2;
    int tmp = 0;
    while (t2 <= t1) {
        tmp = t1 - t2;
        t1 = t2;
        t2 = tmp;
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n, r1, c1, r2, c2; cin >> n >> r1 >> c1 >> r2 >> c2;
        if (r2 == r1 - 1 && c2 == c1 + 2) cout << "Case " << i << ": YES\n";
        else if (r2 == r1 - 1 && c2 == c1 - 2) cout << "Case " << i << ": YES\n";
        else if (r2 == r1 + 1 && c2 == c1 + 2) cout << "Case " << i << ": YES\n";
        else if (r2 == r1 + 1 && c2 == c1 - 2) cout << "Case " << i << ": YES\n";
        else if (r2 == r1 + 2 && c2 == c1 - 1) cout << "Case " << i << ": YES\n";
        else if (r2 == r1 - 2 && c2 == c1 - 1) cout << "Case " << i << ": YES\n";
        else if (r2 == r1 + 2 && c2 == c1 + 1) cout << "Case " << i << ": YES\n";
        else if (r2 == r1 - 2 && c2 == c1 + 1) cout << "Case " << i << ": YES\n";
        else cout << "Case " << i << ": NO\n";
    }
    return 0;
}
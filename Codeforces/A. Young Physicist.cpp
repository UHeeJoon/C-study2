#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, tmp; cin >> n;
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp; x += tmp;
        cin >> tmp; y += tmp;
        cin >> tmp; z += tmp;
    }
    if (x == 0 && y == 0 && z == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
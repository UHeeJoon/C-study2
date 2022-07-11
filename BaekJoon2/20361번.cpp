#include<bits/stdc++.h>
using namespace std;
int n, ballPos, k, ans;
vector <int> cups;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> ballPos >> k;
    cups.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cups[i] = i;
    }

    for (int i = 0, a, b; i < k; i++) {
        cin >> a >> b;
        swap(cups[a], cups[b]);
    }
    for (int i = 1; i <= n; i++) {
        if (cups[i] == ballPos) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}


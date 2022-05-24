#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int>base(n + 1);
    vector<int> upper(n + 1);
    vector<int> lower(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> base[i];
        upper[i] = 1, lower[i] = 1;;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (base[j] < base[i]) {
                upper[i] = max(upper[i], upper[j] + 1);
            }
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = n; j > i; j--) {
            if (base[j] < base[i]) {
                lower[i] = max(lower[i], lower[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, lower[i] + upper[i]);
    }

    cout << ans - 1;
    return 0;
}
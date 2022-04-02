#include<bits/stdc++.h>
using namespace std;
long long dp[32];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * dp[2];
        for (int j = 4; i - j >= 0; j += 2)
            dp[i] += dp[i - j] * 2;
    }
    cout << dp[n] << '\n';
    return 0;
}
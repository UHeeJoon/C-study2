#include<bits/stdc++.h>
using namespace std;
int dp[3][100010], arr[3][100010], t, n;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i < 3; i++)
            for (int j = 1; j <= n; j++)
                cin >> arr[i][j];
        dp[1][1] = arr[1][1], dp[2][1] = arr[2][1];
        for (int i = 2; i <= n; i++) {
            dp[1][i] = max(dp[2][i - 1] + arr[1][i], dp[2][i - 2] + arr[1][i]);
            dp[2][i] = max(dp[1][i - 1] + arr[2][i], dp[1][i - 2] + arr[2][i]);
        }
        cout << max(dp[1][n], dp[2][n]) << '\n';
    }
    return 0;
}
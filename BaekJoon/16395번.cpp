#include<bits/stdc++.h>
using namespace std;
int n;
int dp[35][35];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    dp[1][1] = dp[2][1] = dp[2][2] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    cout << dp[n][k] << '\n';
    return 0;
}
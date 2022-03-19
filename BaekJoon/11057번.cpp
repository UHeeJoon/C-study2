#pragma warning(disable :4996)
#include<bits/stdc++.h>
#define MOD 10007
using namespace std;
int dp[10][1001], n;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i <= 9; i++)
        dp[i][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= j; k++)
                dp[j][i] = (dp[j][i] + dp[k][i - 1]) % MOD;
    int result(0);
    for (int i = 0; i <= 9; i++)
        result += dp[i][n];
    cout << result % MOD << '\n';
    return 0;
}
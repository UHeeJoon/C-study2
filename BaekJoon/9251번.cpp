#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001], A_len, B_len;
char A[1010], B[1010];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B;
    A_len = (int)strlen(A), B_len = (int)strlen(B);
    for (int i = 1; i <= A_len; i++) {
        for (int j = 1; j <= B_len; j++) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    cout << dp[A_len][B_len] << '\n';
    return 0;
}
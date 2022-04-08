#include<bits/stdc++.h>
using namespace std;
int dp[50001] = { 0,1, };
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;  cin >> n;
    for (int i = 2; i <= n; i++) {
        int cnt = 987654321;
        for (int j = 1; j * j <= i; j++) {
            int tmp = i - j * j;
            cnt = min(cnt, dp[tmp]);
        }
        dp[i] = cnt + 1;
    }
    cout << dp[n] << '\n';
    return 0;
}
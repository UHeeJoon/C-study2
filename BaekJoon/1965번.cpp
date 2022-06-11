#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1001];
int dp[1001];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int result = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j <= n; j++) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        result = max(result, dp[i]);
    }
    cout << result << '\n';
    return 0;
}
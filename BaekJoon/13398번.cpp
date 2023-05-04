#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
int arr[100'001];
int dp[1000'001];
int dp2[1000'001];

int main()
{
    FAST_IO;
    int n;
    cin >> n;
    int ans = -987654321;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = dp2[i] = arr[i];
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i] < dp[i - 1] + arr[i]) {
            dp[i] = dp[i - 1] + arr[i];
        }
    }

    for (int i = n; i >= 1; i--) {
        if (arr[i] < dp2[i + 1] + arr[i]) {
            dp2[i] = dp2[i + 1] + arr[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    for (int i = 2; i < n; i++) {
        ans = max(ans, dp[i - 1] + dp2[i + 1]);
    }
    cout << ans << "\n";
    return 0;
}
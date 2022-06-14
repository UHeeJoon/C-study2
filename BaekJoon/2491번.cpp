#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100002];
int dp[100002][2];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    dp[n][0] = dp[n][1] = 1;
    int _max = 1;
    for (int i = n - 1; i > 0; i--) {
        if (arr[i] < arr[i + 1]) {
            dp[i][0] = dp[i + 1][0] + 1;
            dp[i][1] = 1;
        }
        else if (arr[i] > arr[i + 1]) {
            dp[i][1] = dp[i + 1][1] + 1;
            dp[i][0] = 1;
        }
        else {
            dp[i][0] = dp[i + 1][0] + 1;
            dp[i][1] = dp[i + 1][1] + 1;
        }
        _max = max({ dp[i][0], dp[i][1], _max });
    }
    cout << _max << '\n';
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int n;
int arr[100002];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    int result = 1;
    int big = 1, small = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[i + 1])big += 1;
        else big = 1;
        if (arr[i] >= arr[i + 1]) small += 1;
        else small = 1;
        result = max({ big, small, result });
    }
    cout << result << '\n';
    return 0;
}
*/
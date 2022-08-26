#include<bits/stdc++.h>
using namespace std;
#define MAX 1010
#define INF 2147483647
int arr[MAX];
int dp[MAX];
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int _max = 0, idx = 0, tmp = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        int len = 0;
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j])
                len = max(dp[j], len);
        }
        dp[i] = len + 1;

        if (tmp < dp[i]) {
            tmp = dp[i];
            idx = i;
        }
    }

    for (int i = idx; i >= 1; i--) {
        if (tmp == dp[i]) {
            v.push_back(arr[i]);
            tmp--;
        }
    }
    cout << v.size() << '\n';
    for (int i = (int)v.size() - 1; i >= 0; i--) {
        cout << v[i] << ' ';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MAX 200'000 + 10
int arr[MAX];
int n, m;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < m; i++) {
        int num; cin >> num;
        int idx = lower_bound(arr, arr + n, num) - arr;
        if (idx == n || arr[idx] != num) {
            cout << -1 << '\n';
            continue;
        }
        cout << idx << '\n';
    }
    return 0;
}
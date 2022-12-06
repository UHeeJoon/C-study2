#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A, A + N);
    int ans = 4;
    for (int i = 0; i < N; i++) {
        int tmp = distance(A + i, lower_bound(A, A + N, A[i] + 5));
        ans = min(ans, 5 - tmp);
    }
    cout << ans << '\n';
    return 0;
}
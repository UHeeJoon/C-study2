#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int d; cin >> d;
        int sum = 0;
        while (sum + 1 + (sum + 1) * (sum + 1) <= d) {
            sum++;
        }
        cout << sum << '\n';
    }
    return 0;
}
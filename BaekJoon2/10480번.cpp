#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << n << (n & 1 ? " is odd\n" : " is even\n");
    }
    return 0;
}
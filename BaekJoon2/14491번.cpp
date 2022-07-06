#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    string n = "";
    while (t) {
        n.insert(0, 1, t % 9 + '0');
        t /= 9;
    }
    cout << n << '\n';
    return 0;
}
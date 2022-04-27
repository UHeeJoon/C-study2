#include<bits/stdc++.h>
using namespace std;
int GCD(int a, int b) {
    if (b == 0) { return a; }
    return GCD(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, a = 0, b = 0, c = 0;
    cin >> n;
    if (n == 2)
        cin >> a >> b;
    else
        cin >> a >> b >> c;
    int g = GCD(GCD(a, b), c);
    int tmp = g;
    set<int> _set;
    for (int i = 1; i <= tmp; i++) {
        tmp = g / i;
        if (g % i == 0) {
            _set.insert(i);
            _set.insert(tmp);
        }
    }
    for (auto i : _set)
        cout << i << '\n';
    return 0;
}
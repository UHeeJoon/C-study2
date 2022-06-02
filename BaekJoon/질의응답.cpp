#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    return b != 0 ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, m, n, x, y, i, j;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> m >> n >> x >> y;
        int limit = lcm(m, n);
        for (j = x; j <= limit; j += m) {
            int temp = (j % n == 0) ? n : j % n;
            if (temp == y) {
                cout << j << '\n';
                break;
            }
        }
        if (j > limit)
            cout << -1 << '\n';
    }
	return 0;
}

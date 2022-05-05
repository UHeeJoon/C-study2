#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
		a -= x, b -= y;
		if (a < 0) {
			if (c + a < 0) {
				cout << "NO\n";
				continue;
			}
			else {
				c += a;
				a = 0;
			}
		}
		if (b < 0) {
			if (c + b < 0) {
				cout << "NO\n";
				continue;
			}
			else c += b, b = 0;
		}
		if (a >= 0 && b >= 0)
			cout << "YES\n";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0) break;
		if (b > a) {
			int tmp = a;
			a = b, b = tmp;
		}
		if (d > c) {
			int tmp = c;
			c = d, d = tmp;
		}
		if (a <= c && b <= d)
			cout << "100%\n";
		else {
			cout << min(int((double)c / a * 100), int((double)d / b * 100)) << "%\n";
		}
	}
	return 0;
}
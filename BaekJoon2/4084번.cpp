#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		int a, b, c, d, cnt = 0;
		cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0)
			break;
		while (1) {
			if (a == b && b == c && c == d) {
				cout << cnt << '\n';
				break;
			}
			int tmp = d, tmp2 = c;
			d = abs(d - a); c = abs(c - tmp);
			tmp = b;
			b = abs(b - tmp2); a = abs(a - tmp);
			cnt++;
		}
	}
	return 0;
}
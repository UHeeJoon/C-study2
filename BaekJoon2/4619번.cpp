#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		int b, n; cin >> b >> n;
		if (b == 0 && n == 0)break;
		int cnt = 0;
		while (++cnt) {
			if (b < pow(cnt, n)) {
				cnt = abs(b - pow(cnt, n)) < abs(b - pow(cnt - 1, n)) ? cnt : cnt - 1;
				break;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
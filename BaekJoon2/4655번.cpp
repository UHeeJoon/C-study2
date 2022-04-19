#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		double c, sum = 0; cin >> c;
		if (c == 0.00)break;
		int cnt = 0, i = 1;
		while (++i) {
			sum += 1.0 / i;
			cnt++;
			if (sum >= c)
				break;
		}
		cout << cnt << " card(s)\n";
	}
	return 0;
}
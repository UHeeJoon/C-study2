#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		long long a, b; cin >> a >> b;
		if (!a && !b) break;
		int cnt = 0, sum = 0;
		while (a || b) {
			if (a % 10 + b % 10 + sum >= 10) {
				sum = 1;
				cnt++;
			}
			else {
				sum = 0;
			}
			a /= 10, b /= 10;
		}
		cout << cnt << '\n';
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	int sum = 0, sum2 = 0;
	while (t--) {
		int tmp, tmp2; cin >> tmp >> tmp2;
		if (tmp > tmp2)
			sum++;
		if (tmp < tmp2)
			sum2++;
	}
	cout << sum << ' ' << sum2 << '\n';
}
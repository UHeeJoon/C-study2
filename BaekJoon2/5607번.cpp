#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	int sum = 0, sum1 = 0;
	while (t--) {
		int tmp, tmp1; cin >> tmp >> tmp1;
		if (tmp > tmp1)
			sum += tmp + tmp1;
		else if (tmp == tmp1)
			sum += tmp, sum1 += tmp1;
		else
			sum1 += tmp + tmp1;
	}
	cout << sum << ' ' << sum1 << '\n';
	return 0;
}
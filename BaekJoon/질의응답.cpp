#pragma warning(disable :4996)
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed; cout.precision(2);
	int t; cin >> t;
	while (t--) {
		double a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		cout << '$' << a * 350.34 + b * 230.90 + c * 190.55 + d * 125.30 + e * 180.90 << '\n';
	}
	return 0;
}

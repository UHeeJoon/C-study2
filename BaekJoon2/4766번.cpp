#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(2); cout << fixed;
	double tmp, n;
	cin >> n; tmp = n;
	while (n!=999) {
		cin >> n;
		if (n == 999)break;
		cout << n - tmp << '\n';
		tmp = n;
	}
	return 0;
}
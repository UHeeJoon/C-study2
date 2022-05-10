#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		long long n, m; cin >> n >> m;
		long long sum = m * (m + 1) / 2;
		if (n < 0)
			sum -= abs(n) * (abs(n) + 1) / 2;
		else if (n > 1)
			sum -= (n - 1) * (n) / 2;
		cout << "Scenario #" << i << ":\n" << sum << "\n\n";
	}
	return 0;
}
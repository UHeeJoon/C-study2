#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, k; cin >> n >> m >> k;
	int result = min(n / 2, m);
	n = n - result * 2, m = m - result;
	if (n + m < k) {
		result -= ((k - n - m) % 3 == 0 ? (k - n - m) / 3 : (k - n - m) / 3 + 1);
	}
	cout << result << '\n';
	return 0;
}

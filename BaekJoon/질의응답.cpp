#pragma warning(disable: 4996)
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int n;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	if (n == 1 || n == 2)
		cout << 1 << '\n';
	else if (n == 0) cout << 0 << '\n';
	else {
		long long  x = 1, y = 2;
		for (int i = 4; i <= n; i++) {
			long long tmp = (x + y) % MOD;
			x = y, y = tmp;
		}
		cout << y << '\n';
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define MOD 10007
int n, square[1010];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
	cin >> n;
	square[1] = 1, square[2] = 3;
	for (int i = 3; i <= n; i++) {
		square[i] = (square[i - 1] + 2 * square[i - 2]) % MOD;
	}
	cout << square[n];
	return 0;
}
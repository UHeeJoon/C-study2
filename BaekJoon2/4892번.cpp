#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i = 1;
	while (1) {
		int n; cin >> n;
		if (n == 0) break;
		int n1 = n * 3, n2 = n1 % 2 == 1 ? (n1 + 1) / 2 : n1 / 2, n3 = 3 * n2, n4 = n3 / 9;
		cout << i << (n1 % 2 == 1 ? ". odd " : ". even ") << n4 << '\n';
		i++;
	}
	return 0;
}